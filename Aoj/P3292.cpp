#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> a(n);
        for (auto& x: a) cin >> x;
        sort(a.begin(), a.end());
        int curr = 1, res = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] + 1) {
                curr++;
                res = max(res, curr);
            } else {
                curr = 1;
            }
        }
        cout << res << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}