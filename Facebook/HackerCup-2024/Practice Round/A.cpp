#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> s(n);
    for (auto& x: s) cin >> x;
    sort(s.begin(), s.end());
    LL carry = s[0], res;
    if (n == 1) res = carry;
    else res = carry * (2LL * n - 3);
    if (res <= k) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}