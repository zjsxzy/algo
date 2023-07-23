#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int adj[15][15];
int res, n, t, m;
vector<vector<int>> gr;

void dfs(int i) {
    if (i == n) {
        bool flag = true;
        for (int j = 0; j < t; j++) {
            if (gr[j].size() == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res++;
            // for (auto g: gr) {
            //     for (auto x: g) cout << x + 1 << ' ';
            //     cout << endl;
            // }
            // cout << endl;
        }
        return;
    }

    for (int j = 0; j < t; j++) {
        bool flag = true;
        for (auto u: gr[j]) {
            if (adj[u][i] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            // cout << i + 1 << ' ' << it << endl;
            gr[j].push_back(i);
            dfs(i + 1);
            gr[j].pop_back();
        }
        if (flag && gr[j].size() == 0) break;
    }
}

void solve() {
    cin >> n >> t >> m;
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = 1;
    }
    res = 0;
    gr.assign(t, {});
    dfs(0);
    cout << res << endl;
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
