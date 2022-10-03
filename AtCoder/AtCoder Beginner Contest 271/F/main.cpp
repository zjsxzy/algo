#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    LL res = 0;
    vector<map<int, int>> f(n + 1);
    function<void(int, int, int, int)> dfs = [&](int x, int y, int curr, int type) {
        if (type == 0) curr ^= a[x][y];
        if (x + y == n + 1) {
            if (type == 0) {
                f[x][curr]++;
            } else {
                res += f[x].count(curr) ? f[x][curr] : 0;
            }
            return;
        }
        if (type == 1) curr ^= a[x][y];
        if (type == 0) {
            dfs(x + 1, y, curr, type);
            dfs(x, y + 1, curr, type);
        } else {
            dfs(x - 1, y, curr, type);
            dfs(x, y - 1, curr, type);
        }
    };
    dfs(1, 1, 0, 0);
    dfs(n, n, 0, 1);
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

