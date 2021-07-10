#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 100005;
int n, q;
vector<int> adj[MAXN];
int color[MAXN];
bool vst[MAXN];

void dfs(int u, int c) {
    color[u] = c;
    vst[u] = true;
    for (auto &v: adj[u]) {
        if (!vst[v]) {
            dfs(v, 1 - c);
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vst, false, sizeof(vst));
    dfs(1, 0);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (color[u] == color[v]) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

