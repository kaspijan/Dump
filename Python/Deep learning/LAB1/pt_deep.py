import torch
import torch.nn as nn
import torch.optim as optim

#@author Simun Sopar
#neuralna mreža...
class PTDeep(nn.Module):
    def __init__(self, layers, activation_fun):
        super().__init__()
        self.layers = layers    
        self.weights = nn.ParameterList([nn.Parameter(
            torch.normal(torch.zeros(self.layers[i], self.layers[i-1]), torch.ones(self.layers[i], self.layers[i-1])))
                                         for i in range(1, len(self.layers))])
        self.biases = nn.ParameterList([nn.Parameter(
            torch.normal(torch.zeros(self.layers[i]), torch.ones(self.layers[i])))
                                        for i in range(1, len(self.layers))])
        
        self.activation_fun = activation_fun
        
    def forward(self, X):
        H = X
        
        for i in range(0, len(self.biases)-1):
            H = torch.mm(H, (self.weights[i]).T) + self.biases[i]
            H = self.activation_fun(H)
            
        H = torch.mm(H, (self.weights[len(self.biases)-1]).T) + self.biases[len(self.biases)-1]
        sftm = nn.Softmax(dim = 1)
        return sftm(H)
        
    
    def get_loss(self, X, Yoh_, param_lambda = 0.001):
        P = self.forward(X)
        
        w_vec = torch.Tensor([])
        for i in range(1, len(self.biases)):
            w_vec = torch.cat( ( w_vec, torch.reshape( self.weights[i], (-1,) ) ) )
            
        return -torch.mean(torch.log(torch.sum(P * Yoh_, axis = 1))) + param_lambda * torch.norm(w_vec)**2
    
    
#@author Simun Sopar
def train(model, X, Yoh_, param_niter, param_delta, param_lambda = 0.001, saveLoss = False):
    optimizer = optim.SGD(model.parameters(), lr = param_delta)
    L = []
    for i in range(param_niter):
        if (saveLoss == True):
            L.append(model.get_loss(X, Yoh_, param_lambda))
        model.get_loss(X, Yoh_, param_lambda).backward()
        optimizer.step()
        optimizer.zero_grad()
    
    if (saveLoss == True):
        return L
        
    
    
#@author Simun Sopar
def eval(model, X): #input je ndarray
    X = torch.Tensor(X)
    return model.forward(X).detach().numpy()


#@author Simun Sopar
def count_params(model):
    params = 0
    for tens in list(model.named_parameters()):
        print(str(tens[0]) + ': je tensor tipa ' + str(list(tens[1].size())))
        coef = 1
        for siz in list(tens[1].size()):
            coef *= siz
        params += coef
    
    print('Ukupno parametara:', params)