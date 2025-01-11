#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int res = 0;
    for (int i = n / 2, j = 0; i < n; i++) {
        if (a[i] >= a[j] * 2) {
            res++;
            j++;
            if (j == n / 2) break;
        }
    }
    cout << res << '\n';
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