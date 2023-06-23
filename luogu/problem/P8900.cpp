#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> h(n);
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        tot += h[i];
    }
    LL val = tot / n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cnt(n);
    vector<LL> sum(n);
    vector<vector<pair<int, LL>>> g(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (val * cnt[v] > sum[v]) {
                g[u].push_back({v, val * cnt[v] - sum[v]});
            } else if (val * cnt[v] < sum[v]) {
                g[v].push_back({u, sum[v] - val * cnt[v]});
            }
            sum[u] += sum[v];
            cnt[u] += cnt[v];
        }
        sum[u] += h[u];
        cnt[u]++;
    };
    dfs(0, -1);
    priority_queue<pair<LL, int>> pq;
    for (int i = 0; i < n; i++) {
        if (h[i] > val) pq.push({h[i], i});
    }
    vector<pair<pair<int, int>, LL>> ans;
    while (!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();
        while (!g[u].empty()) {
            auto [v, w] = g[u].back();
            if (h[u] - w >= val) {
                ans.push_back({{u, v}, w});
                h[u] -= w;
                h[v] += w;
                if (h[v] > val) pq.push({h[v], v});
                g[u].pop_back();
            } else {
                break;
            }
        }
    }
    std::cout << (int)ans.size() << endl;
    for (auto x: ans) {
        std::cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}