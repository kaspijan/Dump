import numpy as np

#@author Simun Sopar
def binlogreg_train(X, Y_, param_iter = 500, param_delta = 0.05):
    #u X jedan redak odgovara jednom podatku, dim(X) = NxD
    N = X.shape[0]
    
    w = np.random.randn(X.shape[1])
    b = 0
    
    #param_iter = 500
    #param_delta = 0.05
    
    for iteration in range(0, param_iter):
        
        scores = np.dot(X, w) + b
        
        probs = np.array([1/(1 + np.exp(-score)) for score in scores]) #vjer da je u klasi 1
        
        loss = 0
        dL_dscores = []
        for data_index in range(0, N):
            if(Y_[data_index] == 1):
                loss += np.log(probs[data_index])
                dL_dscores.append(probs[data_index] - 1)
            else:
                loss += np.log(1 - probs[data_index])
                dL_dscores.append(probs[data_index])
        loss *= -1/N
        dL_dscores = np.array(dL_dscores)
        
        if (iteration % 10) == 0:
            print("iteration {}: loss {}".format(iteration, loss))
            
        grad_w = 1/N*np.dot(dL_dscores, X)
        grad_b = 1/N*np.dot(dL_dscores, np.ones(N))
        
        w += -param_delta*grad_w
        b += -param_delta*grad_b
        
    return [w, b]
    
    
#@author Simun Sopar
def binlogreg_classify(X, w, b):
    probs = np.array([1/( 1 + np.exp(-np.dot(w,x) - b) ) for x in X])
    return probs
