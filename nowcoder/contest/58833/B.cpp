#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> vst;
vector<vector<int>> adj;

bool dfs(int u, int f) {
    if (vst[u]) {
        return false;
    } else {
        bool res = true;
        for (auto v: adj[u]) {
            vst[v] = true;
            if (dfs(v, !f)) {
                res = false;
            }
            vst[v] = false;
        }
        return res;
    }
}
 

void solve() {
    int n;
    cin >> n;
    adj.assign(n, {});
    vst.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    bool res = dfs(0, 1);
    if (res) cout << "David" << endl;
    else cout << "Adam" << endl;
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