#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= 10; i++) {
        if ((1 << i) >= n) {
            m = i;
            break;
        }
    }
    cout << m << endl;
    fflush(stdout);
    for (int i = 0; i < m; i++) {
        vector<int> ans;
        for (int j = 1; j <= n; j++) {
            if (j >> i & 1) ans.push_back(j);
        }
        cout << ans.size();
        fflush(stdout);
        for (auto x: ans) {
            cout << " " << x;
            fflush(stdout);
        }
        cout << endl;
        fflush(stdout);
    }
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') res += (1 << i);
    }
    if (res == 0) cout << n << endl;
    else cout << res << endl;
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