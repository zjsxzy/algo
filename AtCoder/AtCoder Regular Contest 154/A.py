import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    n = INT()
    A = input()
    B = input()
    A, B = list(A), list(B)
    for i in range(n):
        a, b = A[i], B[i]
        A[i] = max(a, b)
        B[i] = min(a, b)
    A, B = ''.join(A), ''.join(B)
    print(int(A) * int(B) % 998244353)

if __name__ == '__main__':
    main()