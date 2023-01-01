import sys

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    n, m, k = LI()
    restrict = [[] for _ in range(k)]
    for i in range(m):
        x, y = LI()
        x -= 1
        y -= 1
        restrict[y].append(x)
    
    dp = [[0] * (1 << k) for _ in range(n + 1)]
    dp[0][0] = 1
    sum_dp = [[0] * (1 << k) for _ in range(n + 1)]
    sum_dp[0][0] = 0
    for i in range(n):
        for s in range(1 << k):
            if dp[i][s] == 0:
                continue
            for y in range(k):
                ok = True
                for x in restrict[y]:
                    if (s >> x & 1):
                        ok = False
                        break
                if ok:
                    dp[i + 1][s | (1 << y)] += dp[i][s]
                    sum_dp[i + 1][s | (1 << y)] += sum_dp[i][s] * 10 + (y + 1) * dp[i][s]
    
    res, sum_res = 0, 0
    for s in range(1 << k):
        res += dp[n][s] 
        sum_res += sum_dp[n][s]
    print(res)
    print(sum_res)

if __name__ == '__main__':
    main()