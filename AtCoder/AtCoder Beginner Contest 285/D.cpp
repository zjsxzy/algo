#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<string, int> idx;
    int v = 0;
    vector<vector<int>> g(2 * n);
    vector<int> deg(2 * n);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (idx.find(a) == idx.end()) idx[a] = v++;
        if (idx.find(b) == idx.end()) idx[b] = v++;
        g[idx[a]].push_back(idx[b]);
        deg[idx[b]]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: g[u]) {
            deg[v]--;
            if (deg[v]) {
                cout << "No" << endl;
                return;
            } else {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (deg[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}