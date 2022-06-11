#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> s(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> s[i];
    vector<LL> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];
    vector<LL> a(n);
    for (int i = 1; i < n; i++) {
        a[i] = s[i - 1] - a[i - 1];
    }
    map<LL, int> cnt;
    int mul = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[(a[i] - x[j]) * mul]++;
        }
        mul *= -1;
    }
    int res = 0;
    for (auto [_, c]: cnt) res = max(res, c);
    cout << res << endl;
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

