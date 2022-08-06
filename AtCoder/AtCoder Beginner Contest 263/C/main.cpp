#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> ans;

void dfs(int k) {
    if (k == n) {
        for (auto x: ans) cout << x << ' ';
        cout << endl;
        return;
    }
    int i;
    if (ans.size()) i = ans.back() + 1;
    else i = 1;
    for (; i <= m; i++) {
        ans.push_back(i);
        dfs(k + 1);
        ans.pop_back();
    }
}

void solve() {
    cin >> n >> m;
    dfs(0);
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

