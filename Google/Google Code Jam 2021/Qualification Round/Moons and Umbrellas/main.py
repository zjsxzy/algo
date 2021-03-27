# -*- coding: utf-8 -*-

def solve(cs):
    X, Y, S = input().split()
    X, Y = int(X), int(Y)
    if X > 0 and Y < 0:
        S = S.replace("J?", "JC")
        S = S.replace("?C", "JC")
        S = S.replace("??", "JC")
    elif X < 0 and Y > 0:
        S = S.replace("?J", "C?")
        S = S.replace("C?", "CJ")
        S = S.replace("??", "CJ")
    elif X < 0 and Y < 0:
        if X < Y:
            S = S.replace("?J", "C?")
            S = S.replace("C?", "CJ")
            S = S.replace("??", "CJ")

            S = S.replace("J?", "JC")
            S = S.replace("?C", "JC")
            S = S.replace("??", "JC")
        else:
            S = S.replace("J?", "JC")
            S = S.replace("?C", "JC")
            S = S.replace("??", "JC")

            S = S.replace("?J", "C?")
            S = S.replace("C?", "CJ")
            S = S.replace("??", "CJ")

    S = S.replace("?", "")
    cost = 0
    for i in range(0, len(S) - 1):
        if S[i:i + 2] == "CJ":
            cost += X
        elif S[i:i + 2] == "JC":
            cost += Y

    print("Case #{}: {}".format(cs + 1, cost))

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        solve(t)
