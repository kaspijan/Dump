import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np

class _BNReluConv(nn.Sequential):
    def __init__(self, num_maps_in, num_maps_out, k=3, bias=True):
        super(_BNReluConv, self).__init__()
        self.append(nn.BatchNorm2d(num_maps_in))
        self.append(nn.ReLU())
        self.append(nn.Conv2d(num_maps_in, num_maps_out, k, bias = bias))

        
class SimpleMetricEmbedding(nn.Module):
    def __init__(self, input_channels, emb_size=32):
        super().__init__()
        kernel_size = 3
        self.emb_size = emb_size
        self.model = nn.Sequential()
        self.model.append(_BNReluConv(1, emb_size, kernel_size))
        self.model.append(nn.MaxPool2d(kernel_size = 3, stride = 2))
        
        self.model.append(_BNReluConv(emb_size, emb_size, kernel_size))
        self.model.append(nn.MaxPool2d(kernel_size = 3, stride = 2))
        
        self.model.append(_BNReluConv(emb_size, emb_size, kernel_size))
        
    
    def get_features(self, img):
        h = self.model.forward(img)
        h = torch.mean(h, dim = [2,3])
        
        
        if(len(h.shape) == 1):
            h = torch.reshape(h, [1, len(h)])
        
        return h
        


    def loss(self, anchor, positive, negative, margin = 1.0, p = 2):
        a_x = self.get_features(anchor)
        p_x = self.get_features(positive)
        n_x = self.get_features(negative)
        
        if(len(a_x.shape) == 1):
            a_x = torch.reshape(a_x, [1, len(a_x)])
            p_x = torch.reshape(p_x, [1, len(p_x)])
            n_x = torch.reshape(n_x, [1, len(n_x)])
            
        
        
        d_positive = torch.abs(a_x - p_x)**p
        d_negative = torch.abs(a_x - n_x)**p
        d_positive = torch.sum(d_positive, dim = 1)**(1/p)
        d_negative = torch.sum(d_negative, dim = 1)**(1/p)
        
        
        loss = [np.max([d_positive[i].item() - d_negative[i].item() + margin, 0]) for i in range(len(d_positive))]
        
        return torch.tensor(loss, requires_grad = True).sum()
    
    
class IdentityModel(nn.Module):
    def __init__(self):
        super(IdentityModel, self).__init__()

    def get_features(self, img):
        feats = torch.reshape(img, [img.shape[0], -1])
        return feats