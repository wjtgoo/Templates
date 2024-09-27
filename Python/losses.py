import torch
class RelL2Loss(object):
    def __init__(self, p=2, size_average=True, reduction=True):
        super(RelL2Loss, self).__init__()
        assert p > 0
        self.p = p
        self.reduction = reduction
        self.size_average = size_average
    def __call__(self, x, y,batch_size=None):
        if batch_size is None:
            batch_size = x.size()[0]
        
        diff_norms = torch.norm(x.reshape(batch_size,-1) - y.reshape(batch_size,-1), self.p, 1)
        y_norms = torch.norm(y.reshape(batch_size,-1), self.p, 1)
        
        if self.reduction:
            if self.size_average:
                return torch.mean(diff_norms/y_norms)
            else:
                return torch.sum(diff_norms/y_norms)

        return diff_norms/y_norms