import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    n = input()
    s = input()
    s = s.replace('na', 'nya')
    print(s)

if __name__ == '__main__':
    main()