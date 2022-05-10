#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int diff(string& a, string& b) {
    int m = a.size();
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x: s) cin >> x;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = diff(s[i], s[j]);
            res = min(res, t);
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

