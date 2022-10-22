#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans[2 * i] = ans[x] + 1;
        ans[2 * i + 1] = ans[x] + 1;
    }
    for (int k = 1; k <= 2 * n + 1; k++) {
        cout << ans[k] << endl;
    }
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

