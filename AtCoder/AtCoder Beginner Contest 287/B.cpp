#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (s[i].substr(3, 3) == t[j]) {
                flag = true;
                break;
            }
        }
        if (flag) res++;
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