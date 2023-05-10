#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    LL res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= x) {
            j++;
        }
        if (j - i >= 3) {
            res += (LL)(j - i - 1) * (j - i - 2) / 2;
        }
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