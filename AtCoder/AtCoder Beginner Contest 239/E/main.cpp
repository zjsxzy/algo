#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
const int k = 20;
int n, q;
int x[maxn];
vector<int> adj[maxn];
vector<int> val[maxn];

void dfs(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (auto y: val[v]) {
            val[u].push_back(y);
        }
        sort(val[u].rbegin(), val[u].rend());
        val[u].resize(k);
    }
    val[u].push_back(x[u]);
    sort(val[u].rbegin(), val[u].rend());
    val[u].resize(k);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    while (q--) {
        int v, k;
        cin >> v >> k;
        cout << val[v][k - 1] << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

