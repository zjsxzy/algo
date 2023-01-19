#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<vector<int>> ans(m);
    for (int i = 0; i < n; i++) {
        int k = 0;
        if (a[i] < 0) {
            k = max(k, (-a[i] - 1) / (i + 1));
        }
        while (k < m && a[i] + (i + 1) * (k + 1) < n) {
            ans[k].push_back(a[i] + (i + 1) * (k + 1));
            k++;
        }
    }
    for (int i = 0; i < m; i++) {
        sort(ans[i].begin(), ans[i].end());
        int res = 0;
        for (auto x: ans[i]) {
            if (x == res) res++;
        }
        cout << res << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}