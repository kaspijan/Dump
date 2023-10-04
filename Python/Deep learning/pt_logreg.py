import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim

#@author Simun Sopar
class PTLogreg(torch.nn.Module):
    def __init__(self, C, D):
        super().__init__()
        self.D = D
        self.C = C
        
        self.W = nn.Parameter(torch.normal(torch.zeros(self.C, self.D), torch.ones(self.C, self.D)))
        self.b = nn.Parameter(torch.normal(torch.zeros(self.C), torch.ones(self.C)))
        
        #print(self.W, self.b)
    
    def forward(self, X):
        s = torch.mm(X, (self.W).T) + self.b
        smax = nn.Softmax(dim = 1)
        return smax(s)
    
    def get_loss(self, X, Yoh_, param_lambda = 0): #Yoh_ je već one-hot enkodiran Y
        P = self.forward(X)
        w_vec = torch.reshape(self.W, (-1,))
        #param_lambda = 0.001
        #Yoh_ = nn.functional.one_hot(Yoh_.to(torch.int64), self.C)
        return -torch.mean(torch.log(torch.sum(P * Yoh_, axis = 1))) + param_lambda * torch.norm(w_vec)**2
        
    

#@author Simun Sopar
def train(model, X, Yoh_, param_niter, param_delta, param_lambda = 0):
    optimizer = optim.SGD(model.parameters(), lr = param_delta)
    for i in range(param_niter):
        model.get_loss(X, Yoh_, param_lambda).backward()
        optimizer.step()
        optimizer.zero_grad()
    

#@author Simun Sopar    
def eval(model, X):
    X = torch.Tensor(X)
    return model.forward(X).detach().numpy()