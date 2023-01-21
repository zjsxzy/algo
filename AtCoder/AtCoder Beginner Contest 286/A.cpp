#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = p, j = r; i <= q; i++, j++) {
        swap(a[i], a[j]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}