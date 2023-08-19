#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int m;
    cin >> m;
    vector<int> a(m);
    int s = 0;
    for (auto& x: a) cin >> x, s += x;
    int curr = 0;
    for (int i = 0; i < m; i++) {
        curr += a[i];
        if (curr >= (s + 1) / 2) {
            cout << i + 1 << ' ' << (s + 1) / 2 - (curr - a[i]) << endl;
            return;
        }
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