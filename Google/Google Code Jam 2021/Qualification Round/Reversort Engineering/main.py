# -*- coding: utf-8 -*-

def solve(cs):
    T, C = [int(i) for i in input().split()]
    if C < T - 1 or C > T*(T+1) // 2 - 1:
        print("Case #{}: IMPOSSIBLE".format(cs + 1))
    else:
        swaps = []
        for i in range(T - 1):
            c = T - i - 1
            if C <= c:
                break
            else:
                c = min(T-i, C-c+1)
                swaps.append((i, c - 1 + i ))
                C -= c

        res = list(range(1, T+1))
        for i, j in swaps[::-1]:
            res = res[:i] + res[i:j+1][::-1] + res[j+1:]
        res = " ".join([str(i) for i in res])
        print("Case #{}: {}".format(cs + 1, res))

if __name__ == '__main__':

    T = int(input())
    for t in range(T):
        solve(t)
