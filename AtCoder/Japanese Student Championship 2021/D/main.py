# -*- coding: utf-8 -*-

def quick_algorithm(a,b,c):
    a=a%c
    ans=1
    while b!=0:
        if b&1:
            ans=(ans*a)%c
        b>>=1
        a=(a*a)%c
    return ans

def main():
    N, P = input().split()
    N, P = int(N), int(P)
    MOD = 1000000000 + 7
    # res = (P - 1) * (P - 2)**(N - 1) % MOD
    res = (P - 1) * quick_algorithm(P - 2, N - 1, MOD) % MOD
    print(res)

if __name__ == "__main__":
    main()
