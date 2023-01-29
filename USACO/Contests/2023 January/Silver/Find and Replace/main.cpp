#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    map<int, set<int>> g;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        g[(int)s[i]].insert(t[i]);
    }
    int res = 0;
    bool cycle = false;
    set<int> nodes;
    vector<int> vst(512);
    function<void(int)> dfs = [&](int u) {
        if (nodes.count(u)) {
            cycle = true;
            return;
        }
        nodes.insert(u);
        if (vst[u] || g[u].empty()) return;
        auto v = *g[u].begin();
        if (v == u) return;
        dfs(v);
    };
    for (auto [k, v]: g) {
        if (v.size() > 1) {
            cout << -1 << endl;
            return;
        }

        cycle = false;
        dfs(k);
        if (cycle && (int)nodes.size() == 52) {
            cout << -1 << endl;
            return;
        }
        if (cycle) res += (int)nodes.size() + 1;
        else res += (int)nodes.size() - 1;

        for (auto x: nodes) vst[x] = true;
        nodes.clear();
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}