#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> diff(n + 1);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        diff[l]++;
        diff[r + 1]--;
    }
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += diff[i];
        a[i] = tot;
    }
    sort(a.begin(), a.end());
    cout << a[n / 2] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

