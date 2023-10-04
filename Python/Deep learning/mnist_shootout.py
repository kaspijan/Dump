import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import torchvision

import pt_deep


#@author Simun Sopar
def train_7(model, X, Yoh_, param_niter, param_delta = 1e-4, param_lambda = 0.001, variable = False):
    optimizer = optim.Adam(model.parameters(), lr = param_delta)
    if (variable == True):
        scheduler = optim.lr_scheduler.ExponentialLR(optimizer, gamma = 1 - 1e-4)
    for i in range(param_niter):
        model.get_loss(X, Yoh_, param_lambda).backward()
        optimizer.step()
        optimizer.zero_grad()
        if(variable == True):
            scheduler.step()

          

        
        
#@author Simun Spar
#mini-batches
def train_mb(model, x_train, y_train, batchNum = 20, epoch = 50): #train podaci su tenzori!
    


    indexes = [i for i in range(len(y_test))]
    

    for i in range(epoch):
        np.random.shuffle(indexes)
        for n in range(batchNum):
            indexRange = indexes[i*(int)(len(y_test)/batchNum) : (i+1)*(int)(len(y_test)/batchNum)]
            x_batch = torch.Tensor(x_test[indexRange])
            y_batch = torch.Tensor(y_test[indexRange])
            pt_deep.train(model, torch.flatten(x_batch, start_dim = 1), nn.functional.one_hot(y_batch, 10), 1, 0.1)

    

#@author Simun Sopar        
#preciznost i odziv:
def acc(Y_true, Y_pred): #ndarray tip
    P = []
    O = []
    TP_sum = 0
    FP_sum = 0
    FN_sum = 0
    for i in range(10):
        TN = 0; FN = 0; TP = 0; FP = 0
        for j in range(len(Y_true)):
            if(Y_true[j] == i):
                if(Y_pred[j] == i):
                    TP += 1
                else:
                    FN += 1
            else:
                if(Y_pred[j] == i):
                    FP += 1
                else:
                    TN += 1
        P.append(TP/(TP+FP))
        O.append(TP/(TP+FN))
        TP_sum += TP
        FP_sum += FP
        FN_sum += FN
        
    P.append(TP_sum/(TP_sum + FP_sum))
    O.append(TP_sum/(TP_sum + FN_sum))
    return P, O
        
        

#@author Simun Sopar
if __name__ == "__main__":
    import torchvision

    dataset_root = '*/MNIST data'  # change this to your preference
    mnist_train = torchvision.datasets.MNIST(dataset_root, train=True, download=False)
    mnist_test = torchvision.datasets.MNIST(dataset_root, train=False, download=False)

    x_train, y_train = mnist_train.data, mnist_train.targets
    x_test, y_test = mnist_test.data, mnist_test.targets
    x_train, x_test = x_train.float().div_(255.0), x_test.float().div_(255.0)
    
    layers = [784, 10]
    model = pt_deep.PTDeep(layers, torch.relu)

    epoches = 10
    epochSize = 30
    L = []

    for i in range(epoches):
        L_ = pt_deep.train(model, torch.flatten(x_train, start_dim = 1), nn.functional.one_hot(y_train, 10), epochSize, 0.1, saveLoss = True)
        print('Epoch =', i)
        L.append(L_)


    for i in range(0, len(list(model.named_parameters())), 2):
        print(list(model.named_parameters())[i])


        
    #provjera na nekoliko testnih znamenaka
    print('Kratka provjera')
    for i in range(0, 10):
        print(y_test[i], np.argmax(pt_deep.eval(model, torch.reshape(x_test[i], (1, 28*28)).numpy()), axis = 1))

            
    y_pred = pt_deep.eval(model, torch.flatten(x_test, start_dim = 1))
    y_pred = np.argmax(y_pred, axis = 1)

    P1, O1 = acc(y_test, y_pred)
    print(P1, O1)
            
        
    #podjela na validaciju i test
    indexes = [i for i in range(len(y_test))]
    np.random.shuffle(indexes)

    index_test = indexes[0:(int)(len(y_test)*4/5)]
    index_val = indexes[(int)(len(y_test)*4/5):]

    x_val = x_test[index_val]
    y_val = y_test[index_val]
    x_test_2 = x_test[index_test]
    y_test_2 = y_test[index_test]
   

    model = pt_deep.PTDeep(layers, torch.relu)

    train_7(model, torch.flatten(x_test, start_dim = 1), nn.functional.one_hot(y_test, 10), 80, 0.1)
    print(np.argmax(pt_deep.eval(model, torch.flatten(x_train[0:10], start_dim = 1).numpy()), axis = 1))
    print(y_train[0:10])
    