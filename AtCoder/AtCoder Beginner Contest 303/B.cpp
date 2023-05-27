#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    int g[n + 1][n + 1];
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        vector<int> a(n);
        for (auto& x: a) cin >> x;
        for (int i = 0; i < n - 1; i++) {
            g[a[i]][a[i + 1]] = g[a[i + 1]][a[i]] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!g[i][j]) res++;
        }
    }
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