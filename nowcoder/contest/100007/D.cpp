#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    auto is_bipartite = [&]() {
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (auto v: g[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            // cout << u + 1 << ' ' << v + 1 << '\n';
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    };
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (is_bipartite()) {
        if (n % 2 == 0) {
            cout << "Yes" << '\n';
        } else {
            cout << 1 << '\n';
        }
        return;
    }
    // cout << "No" << '\n';
    vector<int> cycles;
    vector<int> color(n, -1);
    vector<int> d(n);
    for (int s = 0; s < n; s++) {
        if (color[s] == -1) {
            queue<pair<int, int>> q;
            q.push({s, -1});
            color[s] = 0;
            d[s] = 0;
            while (!q.empty()) {
                int u = q.front().first;
                int parent = q.front().second;
                q.pop();
                for (auto v: g[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        d[v] = d[u] + 1;
                        q.push({v, u});
                    } else if (color[v] == color[u] && v != parent) {
                        // find odd cycle
                        int leng = abs(d[u] - d[v]) + 1;
                        if (leng & 1) {
                            cycles.push_back(leng);
                            cout << u << ' ' << v << '\n';
                            cout << s << " cycle " << leng << '\n';
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (auto leng: cycles) {
        res += (leng + 1) / 2;
    }
    cout << res << '\n';
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