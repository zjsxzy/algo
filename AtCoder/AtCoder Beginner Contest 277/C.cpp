#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> g;
    int v = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    set<int> vst;
    q.push(1);
    vst.insert(1);
    int res = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res = max(res, u);
        for (auto v: g[u]) {
            if (!vst.count(v)) {
                vst.insert(v);
                q.push(v);
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}