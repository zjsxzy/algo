#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int m;
int adj[10][10];

void solve() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    vector<int> p(8);
    for (int i = 0; i < 8; i++) cin >> p[i];
    map<vector<int>, int> dist;
    dist[p] = 0;
    queue<vector<int>> q;
    q.push(p);
    vector<int> target(8);
    for (int i = 0; i < 8; i++) target[i] = i + 1;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        int d = dist[v];
        if (v == target) {
            cout << d << endl;
            return;
        }
        // find the empty vertex
        vector<int> vis(10, -1);
        for (int i = 0; i < 8; i++) {
            vis[v[i]] = i;
        }
        for (int i = 1; i <= 9; i++) {
            if (vis[i] == -1) {
                for (int j = 1; j <= 9; j++) {
                    if (adj[i][j]) {
                        // move
                        vector<int> new_v;
                        new_v = v;
                        new_v[vis[j]] = i;
                        if (dist.find(new_v) == dist.end()) {
                            dist[new_v] = d + 1;
                            q.push(new_v);
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

