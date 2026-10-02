import torch
import time

t0 = time.perf_counter()

x = torch.tensor([1.0, 2.0])
y = torch.tensor([3.0, 5.0])
# x = torch.rand(1_000_000)
# y = torch.rand(1_000_000)
w = torch.tensor(0.0, requires_grad=True)
b = torch.tensor(0.0, requires_grad=True)
lr = 0.1

for step in range(100):
    y_pred = w * x + b
    loss = ((y_pred - y) ** 2).mean()
    loss.backward()

    assert w.grad is not None
    assert b.grad is not None
    with torch.no_grad():
        w -= lr * w.grad
        b -= lr * b.grad

    assert w.grad is not None
    assert b.grad is not None
    w.grad.zero_()
    b.grad.zero_()

    print(f"{step+1} | w={w.item():.4f} | b={b.item():.4f} | loss={loss.item():.4f}")

print(time.perf_counter() - t0)
