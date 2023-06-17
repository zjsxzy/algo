import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    a = LI()
    res = 0
    for i in range(64):
        if a[i] == 1:
            res += (1 << i)
    print(res)

if __name__ == '__main__':
    main()