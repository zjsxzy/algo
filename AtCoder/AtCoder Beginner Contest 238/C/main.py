# -*- coding: utf-8 -*-

def digits(n):
    res = 0
    while n > 0:
        res += 1
        n = n // 10
    return res

n = int(input())
d = int(digits(n))
x = 9
res = 0
m = 1
t = 0
for i in range(1, d):
    t = (x + 1) * x // 2
    res += t
    x *= 10
    m *= 10
t = (1 + (n - m + 1)) * (n - m + 1) // 2
res += t
mod = 998244353
print(res % mod)
