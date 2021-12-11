#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

vector<vector<int>> adj;
vector<int> vis;
bool flag;
void dfs(int u, int fa) {
    if (!flag) return;
    vis[u] = true;
    for (auto v: adj[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            flag = false;
            return;
        } else {
            dfs(v, u);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) {
            cout << "No" << endl;
            return;
        }
    }
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            flag = true;
            dfs(i, -1);
            if (!flag) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

