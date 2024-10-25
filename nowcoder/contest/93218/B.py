import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def check(s):
    if s.find('@') == -1:
        return False
    l = s.split('@')
    if len(l) != 2:
        return False
    a, b = l[0], l[1]
    if len(a) == 0 or len(a) > 64:
        return False
    if len(b) == 0 or len(b) > 255:
        return False
    if a[0] == '.' or a[-1] == '.':
        return False
    if b[0] == '.' or b[-1] == '.' or b[0] == '-' or b[-1] == '-':
        return False
    for c in a:
        if not str.isalnum(c) and c != '.':
            return False
    for c in b:
        if not str.isalnum(c) and c != '.' and c != '-':
            return False
    return True

def main():
    t = INT()
    for i in range(t):
        s = input()
        if check(s):
            print("Yes")
        else:
            print("No")

if __name__ == '__main__':
    main()