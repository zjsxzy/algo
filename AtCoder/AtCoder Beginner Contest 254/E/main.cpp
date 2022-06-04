#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
vector<int> adj[maxn];
int d[maxn][5];

void bfs(int st) {
    queue<pair<int, int>> q;
    q.push({st, 0});
    set<int> vst;
    vst.insert(st);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int u = p.first, dist = p.second;
        d[st][dist] += u;
        if (dist == 3) continue;
        for (auto v: adj[u]) {
            if (vst.find(v) == vst.end()) {
                vst.insert(v);
                q.push({v, dist + 1});
            }
        }
    }
    for (int k = 1; k <= 3; k++) {
        d[st][k] += d[st][k - 1];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    memset(d, 0, sizeof(d));
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << d[x][k] << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}


