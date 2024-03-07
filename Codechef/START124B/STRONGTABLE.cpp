#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& x: w) cin >> x;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    LL res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (LL)(i + 1) * w[i]);
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}