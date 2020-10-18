#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 100000 + 50;
int N, K;
LL a[MAXN];
LL aSum[MAXN];


LL avg_square(LL sum, int K) {
    LL v1 = sum / K;
    LL v2 = v1 + 1;
    LL n2 = sum % K;
    LL n1 = K - n2;

    LL res = v1 * v1 * n1 + v2 * v2 * n2;
    // printf("avg_square(%lld, %d) = %lld\n", sum, K, res);
    return res;
}


int main() {
    // printf("%lld\n", avg_square(18, 3));
    // printf("%lld\n", avg_square(19, 3));
    // printf("%lld\n", avg_square(20, 3));
    // printf("%lld\n", avg_square(19, 4));

    scanf("%d %d", &N, &K);

    for (int i = 0;  i < N; i++)
        scanf("%lld", a + i);
    sort(a, a + N);

    aSum[N] = 0;
    for (int i = N - 1; i >= 0; i--)
        aSum[i] = aSum[i + 1] + a[i];

    int curK = K;
    LL res = 0;
    for (int i = 0; i < N; i++) {
        LL v1 = aSum[i] / curK;
        if (a[i] > v1) {
            res += avg_square(aSum[i], curK);
            break;
        }
        LL cur = a[i] * a[i];
        res += cur;
        curK --;
        // printf("i=%d, curK=%d, cur=%lld, res=%lld\n", i, curK, cur, res);
    }
    printf("%lld\n", res);
    return 0;
}
