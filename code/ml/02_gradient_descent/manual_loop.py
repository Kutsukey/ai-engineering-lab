import random
xs = [random.random() for _ in range(1_000_000)]
ys = [2 * x + 1 for x in xs]

import time
t0 = time.perf_counter()

#xs = [1.0, 2.0]
#ys = [3.0, 5.0]
w, b, lr = 0.0, 0.0, 0.1
print("step | w        | b        | loss    ")
for step in range(100):
    loss = 0
    errors = []
    for x, y in zip(xs, ys):
        y_pred = w * x + b
        errors.append(y_pred - y)
    for err in errors:
        loss += err**2
    loss /= len(xs)
    db, dw = 0, 0
    for err, x in zip(errors, xs):
        dw += 2 * err * x
        db += 2 * err
    dw /= len(xs)
    db /= len(xs)

    w = w - lr * dw
    b = b - lr * db
    if step % 10 == 0:
        print(f"{step:4d} | w={w:.4f} | b={b:.4f} | loss={loss:.2e}")

print(time.perf_counter() - t0)