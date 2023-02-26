#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    const int inf = 1e9;
    vector<int> f(n, inf);
    vector<vector<int>> adj(n);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1' && i + j + 1 < n) {
                f[i + j + 1] = min(f[i + j + 1], f[i] + 1);
                adj[i + j + 1].push_back(i);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << f[i] << ' ';
    // }
    // cout << endl;
    vector<int> g(n, inf);
    g[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (auto j: adj[i]) {
            g[j] = min(g[j], g[i] + 1);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << g[i] << ' ';
    // }
    // cout << endl;
    for (int k = 1; k < n - 1; k++) {
        int ans = inf;
        // cout << k << ' ' << ans << endl;
        for (int i = max(0, k - m - 1); i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '1' && i + j + 1 > k && i + j + 1 < n) {
                    // cout << k << ' ' << i + 1 << "->" << i + j + 1 + 1 << ' ' << f[i] << ' ' << g[i + j + 1] << endl;
                    ans = min(ans, f[i] + g[i + j + 1] + 1);
                }
            }
        }
        if (ans == inf) ans = -1;
        cout << ans << ' ';
    }
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