#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i + 1);
    }
    int res = 1, A = a[0], l = 1, r = 1;
    for (auto& [k, v]: pos) {
        int m = v.size();
        if (m == 1) continue;
        vector<int> b(m), sum(m);
        sum[0] = 1;
        b[0] = 1;
        int prev = v[0];
        for (int i = 1; i < m; i++) {
            b[i] = 1 - (v[i] - prev - 1);
            sum[i] = sum[i - 1] + b[i];
            prev = v[i];
        }
        /*
        for (auto x: b) cout << x << ' ';
        cout << endl;
        for (auto x: sum) cout << x << ' ';
        cout << endl;
        */
        int mxp = m - 1;
        for (int i = m - 2; i >= 0; i--) {
            if (sum[mxp] - sum[i] + 1 > res) {
                res = sum[mxp] - sum[i] + 1;
                A = k;
                l = v[i];
                r = v[mxp];
            }
            if (sum[i] > sum[mxp]) mxp = i;
        }
    }
    cout << A << ' ' << l << ' ' << r << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}


