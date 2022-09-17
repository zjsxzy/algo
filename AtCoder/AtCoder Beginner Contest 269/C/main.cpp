#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    vector<int> bits;
    vector<LL> ans;
    function<void(int, LL)> dfs = [&](int k, LL num) {
        if (k == 60) {
            ans.push_back(num);
            return;
        }
        if (n >> k & 1) {
            dfs(k + 1, num | (1ll << k));
        }
        dfs(k + 1, num);
    };
    dfs(0, 0);
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x << endl;
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

