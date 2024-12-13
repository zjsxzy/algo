#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    if (n == 1) {
        cout << 0 << ' ' << a[0] << endl;
        return;
    }
    sort(a.begin(), a.end());
    vector<LL> l(n), r(n);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            l[i] = l[i - 1] + a[i] - a[i - 1];
        } else {
            l[i] = l[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            r[i] = r[i + 1] + a[i + 1] - a[i];
        } else {
            r[i] = r[i + 1];
        }
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] >= r[i]) {
            p = i;
            break;
        }
    }
    cout << l[p] + r[p] << ' ' << a[p] - (l[p] - r[p]) / 2 << endl;
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