#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    vector<LL> ss(n + 1);
    for (int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1] + s[i];
    }
    LL res = (-1ll << 60);
    for (int i = 1; i <= n; i++) {
        int j = i + m - 1;
        if (j > n) continue;
        LL t = m * s[j] - (ss[j - 1] - ss[max(0, i - 2)]);
        res = max(res, t);
    }
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

