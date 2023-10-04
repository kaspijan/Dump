import numpy as np

#@author Simun Sopar
def logreg_train(X, Y_, param_iter = 300, param_delta = 0.05):
    C = (int)(np.max(Y_) + 1)
    N = len(X)
    D = len(X[0])
    #initialize weights
    W = np.random.randn(C, D)
    b = np.zeros(C)
    
    
    #param_iter = 300
    #param_delta = 0.05
    
    for itera in range(0, param_iter):
    
        scores = np.dot(X, W.T) + b
        scores = [(s - np.max(s)).tolist() for s in scores]

        expscores = np.exp(scores)

        sumexp = np.dot(expscores, np.ones(C))

        #print(N, D, C, scores)
        
        probs = np.array([expscores[i] / sumexp[i] for i in range(0, N)])
        logprobs = scores - np.stack([np.log(sumexp) for i in range(0, C)]).T
        
        loss = 0
        for i in range(0, N):
            loss += logprobs[i][(int)(Y_[i])]
        loss /= -N

        if (itera % 10 == 0):
            print("iteration {}: loss {}".format(itera, loss))
        
        Y = np.array([[0]*(int)(y) + [1] + [0]*(C - 1 - (int)(y)) for y in Y_])
        
        G_s = probs - Y
        
        dL_ds = np.dot(G_s.T, X)
        
        grad_W = 1/N * dL_ds
        grad_b = 1/N * np.dot(G_s.T, np.zeros(N))
        
        W -= param_delta*grad_W
        b -= param_delta*grad_b

    return W, b

        
#@author Simun Sopar
def logreg_classify(X, W, b):
    C = len(b)
    probs = []
    for x in X:
        S = np.dot(W, x) + b
        S -= np.max(S)
        denom = 0
        for s in S:
            denom += np.exp(s)
        probs.append([np.exp(S[i])/denom for i in range(0, C)])
    return np.array(probs)