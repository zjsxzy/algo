#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), sum(n + 1), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
        pos[sum[i + 1]] = i + 1;
    }
    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (sum[n] - sum[i - 1] < s) break;
        res = min(res, n - (pos[sum[i - 1] + s] - i + 1));
    }
    if (res == INT_MAX) res = -1;
    cout << res << endl;
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

