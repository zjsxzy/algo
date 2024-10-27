#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int unknown = -999999999, mx = 5e8;
    for (auto& x: a) cin >> x;
    vector<int> b = a;
    if (b[0] == unknown) b[0] = mx;
    for (int i = 1; i < n; i++) {
        if (b[i] == unknown) {
            if (b[i - 1] - x >= -mx) b[i] = b[i - 1] - x;
            else b[i] = mx;
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        res += (b[i - 1] - b[i] >= x);
    }
    cout << res << ' ';
    b = a;
    if (b[0] == unknown) b[0] = -mx;
    for (int i = 1; i < n; i++) {
        if (b[i] == unknown) {
            if (b[i - 1] - x + 1 >= -mx) b[i] = b[i - 1] - x + 1;
            else b[i] = -mx;
        }
    }
    res = 0;
    for (int i = 1; i < n; i++) {
        res += (b[i - 1] - b[i] >= x);
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