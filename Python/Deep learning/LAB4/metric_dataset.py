from torch.utils.data import Dataset
from collections import defaultdict
from random import choice
import torchvision
import numpy as np

class MNISTMetricDataset(Dataset):
    def __init__(self, root="./MNIST data", split='train', remove_class = None):
        super().__init__()
        assert split in ['train', 'test', 'traineval']
        self.root = root
        self.split = split
        mnist_ds = torchvision.datasets.MNIST(self.root, train='train' in split, download=True)
        self.images, self.targets = mnist_ds.data.float() / 255., mnist_ds.targets
        self.classes = list(range(10))

        self.target2indices = defaultdict(list)
        
        if(remove_class is not None):       
            self.classes = np.delete(self.classes, remove_class)
            self.images = self.images[self.targets != remove_class]
            self.targets = self.targets[self.targets != remove_class]
            
        for i in range(len(self.images)):
            self.target2indices[self.targets[i].item()] += [i]

    def _sample_negative(self, index):
        index_class = self.targets[index].item()
        sample_class = np.array(self.classes)
        sample_class = sample_class[sample_class != index_class]
        sample_class = choice(sample_class)
        return self.target2indices[sample_class][np.random.randint(0, len(self.target2indices[sample_class]))]


    def _sample_positive(self, index):
        index_class = self.targets[index].item()
        return self.target2indices[index_class][np.random.randint(0, len(self.target2indices[index_class]))]
        


    def __getitem__(self, index):
        anchor = self.images[index].unsqueeze(0)
        target_id = self.targets[index].item()
        if self.split in ['traineval', 'val', 'test']:
            return anchor, target_id
        else:
            positive = self._sample_positive(index)
            negative = self._sample_negative(index)
            positive = self.images[positive]
            negative = self.images[negative]
            return anchor, positive.unsqueeze(0), negative.unsqueeze(0), target_id

    def __len__(self):
        return len(self.images)