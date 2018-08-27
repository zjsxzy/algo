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


const int MAXN = 5000 + 10;
int N, K, a[MAXN];


int main() {
    int testnum; scanf("%d", &testnum);
    for (int ti = 1; ti <= testnum; ti++) {
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++)
            scanf("%d", a + i);
        sort(a, a + N);

        int day = 1;
        int drinkInDay = 0;
        int drink = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] < day)
                continue;
            drink += 1;
            drinkInDay += 1;
            if (drinkInDay == K) {
                drinkInDay = 0;
                day += 1;
            }
        }
        printf("Case #%d: %d\n", ti, drink);
    }
    return 0;
}
