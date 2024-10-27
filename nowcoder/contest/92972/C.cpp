#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    LL s = 0, t = 0;
    for (int i = 0; i < n; i += 2) {
        s += a[i];
        t += a[i + 1];
    }
    s -= a[0]; s += a[n - 1];
    t -= a[n - 1]; t += a[0];
    if (s == t) {
        cout << "draw" << endl;
    } else if (t > s) {
        cout << "kou" << endl;
    } else {
        cout << "yukari" << endl;
    }
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