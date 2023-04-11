#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, c;
    cin >> c >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'G') a[i] |= (1 << j);
        }
    }
    int m = 512;
    vector<vector<int>> dis(m, vector<int>(m, -1e9));
    for (int i = 0; i < n; i++) {
        int l = a[i] / m, r = a[i] % m;
        for (int j = 0; j < m; j++) {
            dis[l][j] = max(dis[l][j], __builtin_popcount(r ^ j));
        }
    }
    for (int i = 0; i < n; i++) {
        int l = a[i] / m, r = a[i] % m, res = 0;
        for (int j = 0; j < m; j++) {
            res = max(res, __builtin_popcount(l ^ j) + dis[j][r]);
        }
        cout << res << endl;
    }
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