#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int res = 1, cnt = a[0];
    for (int i = 1; i < n; i++) {
        if (cnt + a[i] > k) {
            res++;
            cnt = a[i];
        } else {
            cnt += a[i];
        }
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