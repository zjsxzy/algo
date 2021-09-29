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

const int maxn = 50005;
struct edge {
    int u, v, w;
};
edge es[maxn];
int parent[maxn];

bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void solve() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < n + m; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < r; i++) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        es[i] = (edge){x, n + y, -d};
    }
    sort(es, es + r, cmp);
    int sum = 0;
    for (int i = 0; i < r; i++) {
        int fu = find(es[i].u);
        int fv = find(es[i].v);
        if (fu != fv) {
            parent[fv] = fu;
            sum += es[i].w;
        }
    }
    printf("%d\n", 10000 * (n + m) + sum);
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

