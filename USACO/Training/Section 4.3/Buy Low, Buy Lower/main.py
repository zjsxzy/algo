"""
/*
ID: frankzh1
TASK: buylow
LANG: PYTHON2
 */
"""
from itertools import chain
def main():
    fin = open('buylow.in', 'r')
    fout = open('buylow.out', 'w')
    n = map(int, fin.readline().split())[0]
    lines = [map(int, x.split()) for x in fin.readlines()]
    a = list(chain.from_iterable(lines))
    f, g = [1] * n, [1] * n
    res, sum = 1, 0
    for i in range(1, n):
        for j in range(i):
            if a[j] > a[i]:
                if f[j] + 1 == f[i]:
                    g[i] += g[j]
                elif f[j] + 1 > f[i]:
                    f[i] = f[j] + 1
                    g[i] = g[j]
            elif a[i] == a[j]:
                g[j] = 0
        res = max(res, f[i])
    for i in range(n):
        if f[i] == res:
            sum += g[i]
    # print(res, sum)
    fout.write(str(res) + ' ' + str(sum) + '\n')
    fout.close()

if __name__ == '__main__':
    main()