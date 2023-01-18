#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    LL curr = 0, prev = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == prev || a[i] == (prev + 1) % m) {
            curr += a[i];
        } else {
            curr = a[i];
        }
        mx = max(mx, curr);
        prev = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == prev || a[i] == (prev + 1) % m) {
            curr += a[i];
        } else {
            curr = a[i];
        }
        mx = max(mx, curr);
        prev = a[i];
    }
    cout << max(0LL, sum - mx) << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}