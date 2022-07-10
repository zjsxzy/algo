#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[b].push_back(a);
    }
    set<int> st;
    function<void(int)> dfs = [&](int u) {
        st.insert(u);
        if (st.size() > K) return;
        for (auto v: adj[u]) {
            if (st.find(v) == st.end()) {
                dfs(v);
            }
        }
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        dfs(i);
        if (st.size() > K) res++;
        st.clear();
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

