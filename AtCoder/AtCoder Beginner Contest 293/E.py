import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def geometric(n, b, m):
    T = 1
    e = b % m
    res = 0
    while n > 0:
        if n & 1 == 1:
            res = (e * res + T) % m
        T = ((e + 1) * T) % m
        e = (e * e) % m
        n = n // 2
    print(res)

def main():
    a, x, m = MAP()
    geometric(x, a, m)

if __name__ == '__main__':
    main()