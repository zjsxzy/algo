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

const int maxn = 50 + 5;
int n, m, init[maxn][maxn], curHgt[maxn][maxn], low[maxn][maxn], par[maxn*maxn];

int findPar(int x) {
    if (par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void fill(int rainHeight) {
    for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++)
        low[i][j] = curHgt[i][j] < rainHeight;
    // init disjoint set
    for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++)
        par[i*(m+1)+j] = i*(m+1)+j;
    for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++)
    if (low[i][j]) {
        if (i - 1 >= 0 && low[i-1][j]) {
            int p1 = findPar(i*(m+1)+j);
            int p2 = findPar((i-1)*(m+1)+j);
            par[p1] = p2;
        }
        if (j -1 >= 0 && low[i][j-1]) {
            int p1 = findPar(i*(m+1)+j);
            int p2 = findPar(i*(m+1)+j-1);
            par[p1] = p2;
        }
    }
    int outsidePar = findPar(0);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (low[i][j] && findPar(i*(m+1)+j) != outsidePar)
            curHgt[i][j] = rainHeight;
}

int main() {
    //fropen("test.in", "r");
    int test; scanf("%d", &test);
    for (int ti = 1; ti <= test; ti++) {
        scanf("%d %d", &n, &m);
        int maxHeight = 0;
        for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++)
            init[i][j] = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            scanf("%d", &init[i][j]);
        for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++) {
            curHgt[i][j] = init[i][j];
            maxHeight = max(maxHeight, init[i][j]);
        }
        for (int rainHeight = 1; rainHeight <= maxHeight; rainHeight++) {
            fill(rainHeight);
        }
        // debug
        //for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++)
        //    printf("%d%c", curHgt[i][j], j==m+1?'\n':',');
        int diff = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            diff += curHgt[i][j] - init[i][j];
        printf("Case #%d: %d\n", ti, diff);
    }
    return 0;
}
