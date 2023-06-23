#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> a, b, sum;

LL get_sum(int l, int r) {
    if (l > r) return 0;
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

void solve() {
    int n;
    cin >> n;
    a.resize(n), b.resize(n), sum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    sum[0] = b[0];
    LL ans = b[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + b[i];
        ans += b[i] * (i + 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int i;
        LL j;
        cin >> i >> j;
        i--;
        if (a[i] == j) {
            cout << ans << endl;
        } else if (a[i] < j) {
            int l = lower_bound(b.begin(), b.end(), a[i] + 1) - b.begin();
            int r = upper_bound(b.begin(), b.end(), j) - b.begin() - 1;
            LL res = ans - l * a[i] + (r + 1) * j - get_sum(l, r);
            cout << res << endl;
        } else {
            int l = lower_bound(b.begin(), b.end(), j + 1) - b.begin();
            int r = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
            LL res = ans - (r + 1) * a[i] + (l + 1) * j + get_sum(l, r - 1);
            cout << res << endl;
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