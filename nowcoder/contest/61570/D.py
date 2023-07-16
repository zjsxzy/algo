import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    n = INT()
    res = 4 * n * n * (n * n + 1) // 2
    print(res % 1000000007)
    res -= 4 * (n - 1) * (4 * (n - 1) + 1) // 2
    print(res % 1000000007)
    res -= 10
    print(res % 1000000007)

if __name__ == '__main__':
    main()