#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int f[20][1 << 20], g[20][1 << 20];
int vst[20];
int e[20][20];
int n;

void dfs(int u, int p) {
    vst[u] = true;
    for (int v = 0; v < n; u++) {
        if (!vst[v]) {
            dfs(v, u);
        } else if (v != p) {

        }
    }
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    for (int i = 0; i < n; i++) vst[i] = 0;
    memset(e, 0, sizeof(e));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        dfs(i, -1);
    }
    LL res = 1e18;
    for (int st = 0; st < n; st++) {
        if (vst[st]) continue;
        for (int u = 0; u < n; u++) {
            for (int s = 0; s < (1 << n); s++) {
                f[u][s] = 1e9;
                g[u][s] = 1e9;
            }
        }
        f[st][1 << st] = 0;
        g[st][1 << st] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int u = 0; u < n; u++) {
                if (s >> u & 1) {
                    if (f[u][s] == 1e9) continue;
                    LL nodes = f[u][s], edges = g[u][s];
                    for (int v = 0; v < n; v++) {
                        if (e[u][v] && !(s >> v & 1) && (nodes + a[v]) * (edges + e[u][v]) < (LL)f[v][s | (1 << v)] * g[v][s | (1 << v)]) {
                            f[v][s | (1 << v)] = nodes + a[v];
                            g[v][s | (1 << v)] = edges + e[u][v]; 
                        }
                    }
                }
            }
        }
        for (int s = 1; s < (1 << n); s++) {
            for (int u = 0; u < n; u++) {
                if (u != st && e[u][st] && __builtin_popcount(s) > 2) {
                    LL nodes = f[u][s], edges = g[u][s];
                    res = min(res, (nodes + a[st]) * (edges + e[u][st]));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dsu.same(st, i)) vst[i] = 1;
        }
    }
    if (res == 1e18) res = -1;
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}