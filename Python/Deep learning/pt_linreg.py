import torch
import torch.optim as optim
import numpy as np

#@author Simun Sopar
if __name__ == "__main__":
    a = torch.randn(1, requires_grad = True)
    b = torch.randn(1, requires_grad = True)



    realA = 3
    realB = 1

    #generiranje podataka za fit:
    numOfData = 10
    xRange = 5
    X = torch.rand(numOfData)*xRange
    Y = torch.tensor([realA*x + realB + np.random.normal() for x in X])


    optimizer = optim.SGD([a,b], lr = 0.1)

    for i in range(100):
        Y_ = a*X + b

        diff = (Y - Y_)

        loss = (diff**2).mean()

        loss.backward()

        optimizer.step()
        print(f'step: {i}\ngrad a: {a.grad}, grad b: {b.grad}')
        print(f'Analitički gradijenti:\ngrad a:', '{:.4f}'.format(-2*torch.dot(X,diff)/numOfData), 
              'grad b:', '{:.4f}'.format(-2*torch.sum(diff)/numOfData),'\n')
        optimizer.zero_grad()


    print(f'loss: {loss}\nY: {Y}\nY_: {Y_}\na: {a}, b: {b}\n')