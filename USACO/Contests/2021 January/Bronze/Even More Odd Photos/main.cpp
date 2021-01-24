#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if (odd > even) {
        int diff = odd - even;
        int res = even * 2;
        if (diff % 3 == 0) {
            res += diff / 3 * 2;
        } else if (diff % 3 == 2) {
            res += diff / 3 * 2 + 1;
        } else {
            res += (diff - 2) / 3 * 2 + 1;
        }
        cout << res << endl;
    } else {
        if (odd == even || even == odd + 1) {
            cout << odd + even << endl;
        } else {
            cout << odd * 2 + 1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

