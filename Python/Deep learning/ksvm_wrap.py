from sklearn import svm


#@author Simun Sopar
class KSVMWrap():
    def __init__(self, X, Y_, param_svm_c = 1, param_svm_gamma = 'auto'):
        self.X = X
        self.Y_ = Y_
        self.clf = svm.SVC(C = param_svm_c, gamma = param_svm_gamma)
        self.clf.fit(X, Y_)
    
    #@author Simun Sopar
    def predict(self, X):
        return self.clf.predict(X)
    
    #@author Simun Sopar
    def get_scores(self, X):
        Y = self.clf.predict(X)
        TP = 0
        FP = 0
        TN = 0
        FN = 0
        for i in range(len(Y)):
            if(Y[i] == self.Y_[i]):
                if(Y[i] > 0):
                    TP += 1
                else:
                    TN += 1
            else:
                if(Y[i] > 0):
                    FP += 1
                else:
                    FN += 1
                    
        return [TP/(TP + FP), TP/(TP + FN), FP/(FP + TN), TN/(TN + FP)] #P, TPR, FPR, S
    
    #@author Simun Sopar    
    def support(self):
        return self.clf.support_