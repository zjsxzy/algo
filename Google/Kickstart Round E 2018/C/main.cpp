#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;


const int MAXN = 5;
const int MAXN3 = 15;
int N, N3;

int scoreA[MAXN3], slotCountA[MAXN3], slotSumA[MAXN3];
int scoreB[MAXN3], slotCountB[MAXN3], slotSumB[MAXN3];



int get_game_result() {
    int flag = 0;
    if (slotSumA[0] > slotSumB[0]) flag ++;
    if (slotSumA[1] > slotSumB[1]) flag ++;
    if (slotSumA[2] > slotSumB[2]) flag ++;
    return flag >= 2;
}


void dfsB(int i, LL &win, LL &total) {
    if (i == N3) {
        total += 1;
        int isWin = get_game_result();
        if (isWin)
            win += 1;
        return;
    }
    for (int g = 0; g < 3; g++) {
        if (slotCountB[g] >= 3)
            continue;
        slotCountB[g] += 1;
        slotSumB[g] += scoreB[i];
        dfsB(i + 1, win, total);
        slotSumB[g] -= scoreB[i];
        slotCountB[g] -= 1;
    }
}


double dfsA(int i) {
    if (i == N3) {
        memset(slotCountB, 0, sizeof(slotCountB));
        memset(slotSumB, 0, sizeof(slotSumB));
        LL win = 0, total = 0;
        dfsB(0, win, total);
        // printf("%d, %d, %.9f\n", win, total, (double) win / total);
        return (double) win / total;
    }
    double result = 0;
    for (int g = 0; g < 3; g++) {
        if (slotCountA[g] >= 3)
            continue;
        slotCountA[g] += 1;
        slotSumA[g] += scoreA[i];
        double tmp = dfsA(i + 1);
        result = max(tmp, result);
        slotSumA[g] -= scoreA[i];
        slotCountA[g] -= 1;
    }
    return result;
}


int main() {
    int testnum; scanf("%d", &testnum);
    for (int ti = 1; ti <= testnum; ti++) {
        scanf("%d", &N);
        N3 = N * 3;;
        for (int i = 0; i < N3; i++) scanf("%d", scoreA + i);
        for (int i = 0; i < N3; i++) scanf("%d", scoreB + i);

        memset(slotCountA, 0, sizeof(slotCountA));
        memset(slotSumA, 0, sizeof(slotSumA));
        double result = dfsA(0);
        printf("Case #%d: %.9f\n", ti, result);
    }
    return 0;
}
