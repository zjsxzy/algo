#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    LL res = 0;
    for (int i = 0; i < n; i++) res += 1ll * a[i] * b[i];
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

