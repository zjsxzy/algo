/*
ID: frankzh1
TASK: fence
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 505;
const int n = 500;
int deg[MAXN];
int g[MAXN][MAXN];
vector<int> res;

void euler(int u) {
    for (int v = 1; v <= n; v++) {
        if (g[u][v]) {
            g[u][v]--;
            g[v][u]--;
            euler(v);
        }
    }
    res.push_back(u);
}

void solve() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v]++;
        g[v][u]++;
        deg[u]++; deg[v]++;
    }
    int st = 1;
    for (int u = 1; u <= n; u++) {
        if (deg[u] & 1) {
            st = u;
            break;
        }
    }
    euler(st);
    reverse(res.begin(), res.end());
    for (auto &x: res) {
        cout << x << endl;
    }
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    solve();
    return 0;
}

