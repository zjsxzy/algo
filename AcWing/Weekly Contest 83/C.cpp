#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    int N = n / 2;
    if (N > m) {
        cout << -1 << endl;
        return;
    }
    if (n == 1 && m > 0) {
        cout << -1 << endl;
        return;
    } 
    vector<int> ans;
    if (N > 0) {
        ans.push_back(m - N + 1);
        ans.push_back(2 * (m - N + 1));
    }
    for (int i = (m - N + 1), j = 0; j < N - 1; i++, j++) {
        ans.push_back(2 * i + 1);
        ans.push_back(2 * i + 2);
    }
    if (n & 1) ans.push_back(1e9);
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}