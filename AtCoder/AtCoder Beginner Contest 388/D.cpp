#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), diff(n + 2);
    for (auto i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    int x = diff[0];
    for (int i = 1; i <= n; i++) {
        x += diff[i];
        if (x >= n - i) {
            cout << x - (n - i) << ' ';
            diff[i + 1] += 1;
            diff[n + 1] -= 1;
        } else {
            cout << 0 << ' ';
            diff[i + 1] += 1;
            diff[i + x + 1] -= 1;
        }
    }
    cout << '\n';
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