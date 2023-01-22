#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, inf));
    vector<int> deg(n);
    int res = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        deg[a]++; deg[b]++;
        d[a][b] = d[b][a] = min(d[a][b], c);
        res += c;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (deg[i] & 1) v.push_back(i);
    }
    if (v.size() == 0) {
        cout << res << endl;
        return;
    }
    // floyd
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    // bitmask dp
    int sz = v.size();
    vector<int> dp(1 << sz, inf);
    dp[0] = 0;
    for (int s = 0; s < (1 << sz); s++) {
        if (dp[s] == inf) continue;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int a = v[i], b = v[j];
                if (!(s >> i & 1) && !(s >> j & 1)) {
                    dp[s | (1 << i) | (1 << j)] = min(dp[s | (1 << i) | (1 << j)], dp[s] + d[a][b]);
                }
            }
        }
    }
    cout << res + dp[(1 << sz) - 1] << endl;
}

int main() {
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}