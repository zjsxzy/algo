#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        gr[v].push_back(u);
        deg[u]++;
    }
    vector<int> d(n, 1e9);
    d[n - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n - 1});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (p.first > d[u]) continue;
        for (auto v: gr[u]) {
            deg[v]--;
            int nd = p.first + deg[v] + 1;
            if (nd < d[v]) {
                d[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    cout << d[0] << endl;
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

