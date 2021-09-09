"""
/*
ID: frankzh1
TASK: vans
LANG: PYTHON2
 */
"""

def main():
    fin = open('vans.in', 'r')
    fout = open('vans.out', 'w')
    n = map(int, fin.readline().split())[0]
    f, g = [0] * max(5, n + 1), [0] * max(5, n + 1)
    f[1], f[2], f[3], f[4] = 0, 1, 2, 6
    g[1], g[2], g[3], g[4] = 1, 1, 4, 8
    for i in range(5, n + 1):
        f[i] = f[i - 1] + g[i - 1]
        g[i] = f[i - 1] * 2 + g[i - 1] + g[i - 2] - g[i - 3]
    fout.write(str(2 * f[n]) + '\n')
    fout.close()

if __name__ == '__main__':
    main()
