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

const int MAXN = 200005;
LL a[MAXN], b[MAXN];
vector<int> adj[MAXN];
int vis[MAXN];
int n, m;
int idx;
LL sum_a, sum_b;

void dfs(int u) {
    vis[u] = idx;
    sum_a += a[u];
    sum_b += b[u];
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    memset(vis, 0, sizeof(vis));
    sum_a = 0, sum_b = 0;
    idx = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            idx++;
            sum_a = 0;
            sum_b = 0;
            dfs(i);
            if (sum_a != sum_b) {
                flag = false;
            }
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

