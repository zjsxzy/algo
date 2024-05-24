# -*- coding: utf-8 -*-

from math import gcd

def restore_array(a):
    n = len(a)
    b = [0] * n
    b[0] = a[0]

    for i in range(1, n):
        b[i] = a[i] // gcd(a[i], a[i-1])

    return b

# 示例
a = [6, 6, 6]
b = restore_array(a)
print("原数组 b:", b)

