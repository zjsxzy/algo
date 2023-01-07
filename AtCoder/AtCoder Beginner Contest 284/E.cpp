#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    set<int> st;
    function<void(int)> dfs = [&](int u) {
        res++;
        if (res >= (int)1e6) return;
        for (auto v: adj[u]) {
            if (st.count(v)) continue;
            st.insert(v);
            dfs(v);
            st.erase(v);
        }
    };
    st.insert(0);
    dfs(0);
    cout << min(res, (int)1e6) << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}