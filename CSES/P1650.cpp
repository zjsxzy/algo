#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (s[r] ^ s[l - 1]) << endl;
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