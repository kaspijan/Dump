import numpy as np
import matplotlib.pyplot as plt

#@author Simun Sopar
class Random2DGaussian:
    
    minx = -10
    maxy = 10
    
    miny = -10
    maxx = 10
    
    
   
    def _init_(self):
        self.mu = (0,0)
    
    
    
    
    
    def get_sample(self, n):
        randData = [0, 0]
        randSample = []

        mu = ((self.maxx - self.minx) * np.random.random_sample() + self.minx, (self.maxy - self.miny) * np.random.random_sample() + self.miny)
    
        D = np.array([[np.random.random_sample() * (self.maxx - self.minx) / 5, 0],[0 , np.random.random_sample() * (self.maxy - self.miny) / 15]])
    
        phi = np.random.random_sample() * 2 * np.pi
        R = np.array([[np.cos(phi), -np.sin(phi)], [np.sin(phi), np.cos(phi)]])
    
        sigma_matrix = np.dot(np.dot(R.T, D), R)
        
        for i in range(0, n):
            randSample.append(np.random.multivariate_normal(mu, sigma_matrix).tolist())

        return np.array(randSample)
    
   

    

#@author Simun Sopar
def sample_gauss_2d(C, N):
    y = np.array([])
    X = np.array([[0,0]])
    for i in range(0, C):
        y = np.concatenate((y, i*np.ones(N)))
        G = Random2DGaussian()
        X = np.concatenate((X, G.get_sample(N)))
    X = np.delete(X, 0, 0)
    return X, y


#@author Simun Sopar
def sample_gmm_2d(K, C, N):
    y = np.array([])
    X = np.array([[0,0]])
    G = [Random2DGaussian() for i in range(K)]
    G_y = np.random.randint(C, size=K)
    for i in range(K):
        y = np.concatenate((y, G_y[i]*np.ones(N)))
        X = np.concatenate((X, G[i].get_sample(N)))
    X = np.delete(X, 0, 0)
    return X, y


#@author Simun Sopar
def eval_perf_binary(Y, Y_): #za oznake 0, 1
    TP = 0; FP = 0; TN = 0; FN = 0;
    for i,y_ in enumerate(Y_):
        if(y_ == 1):
            if(Y[i] == y_):
                TP+=1
            else:
                FN+=1
        else:
            if(Y[i] == y_):
                TN+=1
            else:
                FP+=1
    return [(TP+TN)/len(Y), TP/(TP + FP), TP/(TP + FN)]


#@author Simun Sopar
def eval_AP(Y_r): #uzima rangiranu listu
    
    sum1 = 0
    sum2 = 0
    
    for i in range(0, len(Y_r)):
        
        TP = 0
        FP = 0
        
        for j in range(i, len(Y_r)):
                if(Y_r[j] == 1):
                    TP+=1
                else:
                    FP+=1
                    
        sum1 += Y_r[i]*TP/(TP + FP)
        sum2 += Y_r[i]
        
    return sum1/sum2


#@author Simun Sopar
def graph_data(X, Y_, Y, special = []):
    
    X_T = []
    X_F = []
    Y_T = []
    Y_F = []
    
    
    size = 20*np.ones(len(Y))
    size_T = []
    size_F = []
    
    if (len(special) > 0):
        size[special] = 60
        
    for i in range(0, len(Y)):
        if(Y[i]==Y_[i]):
            size_T.append(size[i])
            X_T.append(X[i].tolist())
            if(Y_[i] == 1):
                Y_T.append('white')
            else:
                Y_T.append('gray')
                
        else:
            size_F.append(size[i])
            X_F.append(X[i].tolist())
            if(Y_[i] == 1):
                Y_F.append('white')
            else:
                Y_F.append('gray')
     
    X_T = np.array(X_T)
    X_F = np.array(X_F)
    
    if(len(X_T > 0)):
        plt.scatter(X_T[:, 0], X_T[:, 1], c = Y_T, edgecolor='black', marker='o', s = size_T)
       
    if(len(X_F > 0)):
        plt.scatter(X_F[:, 0], X_F[:, 1], c = Y_F, edgecolor='black', marker='s', s = size_F)
        
    
        
    
    #plt.show()
    
    
    
#@author Simun Sopar
def graph_surface(fun, rect, offset, width, height):
    x_axis = np.linspace(rect[0][0], rect[1][0], width)
    y_axis = np.linspace(rect[0][1], rect[1][1], height)
    
    grid1, grid2 = np.meshgrid(x_axis, y_axis)
    grid1 = grid1.flatten()
    grid2 = grid2.flatten()
    
    grid = np.stack([grid1, grid2], axis = 1)

    colors = fun(grid)
    colors = colors.reshape(height, width)
    
    
    
    c = plt.pcolormesh(x_axis, y_axis, colors, vmin = offset - np.max([colors.min(), colors.max()]), vmax = offset + np.max([colors.min(), colors.max()]))
    #plt.colorbar(c)
    plt.contour(x_axis, y_axis, colors, [offset], colors = 'black')