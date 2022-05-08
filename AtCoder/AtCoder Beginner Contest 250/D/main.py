# -*- coding: utf-8 -*-

n = int(input())

N = 1000000
b = [0] * N
prime = []
for i in range(2, N):
    if (b[i] == 0):
        prime.append(i)
        for j in range(2, N):
            if (i * j >= N):
                break
            b[i * j] = 1

res = 0
sz = len(prime)
for i in range(sz):
    p = prime[i]
    lo = i + 1
    hi = sz - 1
    while (lo <= hi):
        mid = (lo + hi) // 2
        q = prime[mid]
        t = p * q * q * q
        if (t > n):
            hi = mid - 1
        else:
            lo = mid + 1

    res += (hi - i)

print(res)
