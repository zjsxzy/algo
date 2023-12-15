#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> s(m);
    for (auto& x: s) cin >> x;
    vector<vector<int>> vec(m);
    for (int i = 0; i < q; i++) {
        int p, k;
        cin >> p >> k;
        p--;
        vec[p].push_back(k);
    }
    vector<int> sum(n + 2);
    for (int i = 0; i < m; i++) {
        if (vec[i].empty()) continue;
        sort(vec[i].begin(), vec[i].end());
        int l = -1, r = -1;
        for (auto v: vec[i]) {
            if (v > r) {
                if (l != -1) {
                    // cout << i << ' ' << l << ' ' << r << endl;
                    sum[l] += 1;
                    sum[r + 1] += -1;
                }
                l = v, r = min(v + s[i] - 1, n);
            } else {
                r = min(v + s[i] - 1, n);
            }
        }
        // cout << i << ' ' << l << ' ' << r << endl;
        sum[l] += 1;
        sum[r + 1] += -1;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        cout << sum[i] << ' ';
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