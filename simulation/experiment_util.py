import torch
from typing import Union


def get_device():
    if torch.cuda.is_available():
        return torch.device('cuda')
    return torch.device('cpu')


def to_device(data: Union[torch.Tensor, torch.Module], device):
    if isinstance(data, (list, tuple)):
        return [to_device(x, device) for x in data]
    return data.to(device, non_blocking=True)


def accuracy(predicted: torch.Tensor, actual: torch.Tensor):
    max_values, max_indices = torch.max(predicted, dim=1)
    return torch.tensor(torch.sum(max_indices == actual).item() / len(max_indices))
