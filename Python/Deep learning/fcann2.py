import numpy as np

#@author Simun Sopar
def fcann2_train(X, Y_, H=5, param_niter = 200, param_delta = 1e-2):
    
    def ReLU(x_vec):
        relX = np.zeros(len(x_vec))
        for i,x in enumerate(x_vec):
            if x > 0:
                relX[i] = x
        return relX
    
    D = len(X[0])
    C = (int)(np.max(Y_)) + 1
    
    #inicijalizacija matrica težina
    W1 = np.random.randn(H, D)
    b1 = np.random.randn(H)
    
    W2 = np.random.randn(C, H)
    b2 = np.random.randn(C)
    
    
    #param_niter = 200
    #param_delta = 1e-2
    
    for itera in range(param_niter):
        scores1 = np.dot(X, W1.T) + b1
        H1 = np.array([ReLU(s) for s in scores1])
        scores2 = np.dot(H1, W2.T) + b2

        Gs2 = []

        for i,s in enumerate(scores2):
            s -= np.max(s)
            sexp = np.exp(s)
            P_vec = sexp/np.sum(sexp)
            Y_vec = np.zeros(C)
            Y_vec[(int)(Y_[i])] = 1
            Gs2.append(Y_vec - P_vec)

        Gs2 = np.array(Gs2)
        gradW2 = -np.dot(Gs2.T, H1)
        gradb2 = -np.sum(Gs2, axis=0)  #gradb2 = np.dot(Gs2.T, np.ones(len(X)))

        gradW1 = []
        gradb1 = []
        for i in range(H):
            D_i = np.diag([np.max([0, np.sign(s[i])]) for s in scores1])
            dW1_vec = np.dot(np.dot(np.dot(W2.T, Gs2.T), D_i), X)[i]
            gradW1.append(-dW1_vec)
            gradb1.append( -np.sum( np.dot(np.dot(W2.T, Gs2.T), D_i)[i] ) )
    
        W1 -= param_delta * np.array(gradW1)
        b1 -= param_delta * np.array(gradb1)
        W2 -= param_delta * gradW2
        b2 -= param_delta * gradb2
    
    return W1, b1, W2, b2
    
    
#@author Simun Sopar
def fcann2_classify(X, W1, b1, W2, b2):
    
    def ReLU(x_vec):
        relX = np.zeros(len(x_vec))
        for i,x in enumerate(x_vec):
            if x > 0:
                relX[i] = x
        return relX
    
    scores1 = np.dot(X, W1.T) + b1
    H1 = np.array([ReLU(s) for s in scores1])
    scores2 = np.dot(H1, W2.T) + b2
    P = []
    
    for i,s in enumerate(scores2):
            s -= np.max(s)
            sexp = np.exp(s)
            P_vec = sexp/np.sum(sexp)
            P.append(P_vec)
        
    return np.array(P)