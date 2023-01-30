#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> r[i][j];
        }
    }
    vector<int> ans(n);
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] + r[i][i + 1];
        bool ok = true;
        int mx = INT_MIN, mn = INT_MAX;
        for (int j = i; j < n; j++) {
            mx = max(mx, ans[j]);
            mn = min(mn, ans[j]);
            if (mx - mn != r[i][j]) {
                ok = false;
                break;
            }
        }
        if (!ok) ans[i] = ans[i + 1] - r[i][i + 1];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i == n - 1) cout << endl;
        else cout << ' ';
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