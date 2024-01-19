#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    s[1] = 1;
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + (a[i] != a[i - 1]);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] + (s[l] == s[l - 1]) << endl;
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