#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    map<int, int> deg;
    set<int> st;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg.find(i) != deg.end() && deg[i] == 1) {
            st.insert(i);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        auto x = st.begin();
        int u = *g[*x].begin();
        ans.push_back(deg[u]);
        deg[u] = 0;
        st.erase(u);
        for (auto v: g[u]) {
            deg[v]--;
            st.erase(v);
            g[v].erase(u);
            for (auto nv: g[v]) {
                deg[nv]--;
                g[nv].erase(v);
                if (deg[nv] == 1) st.insert(nv);
            }
        }
        g[u].clear();
    }
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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