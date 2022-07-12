#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto& s: grid) cin >> s;
    vector<string> ans = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                int k = 0;
                if (grid[j][n - i - 1] == '1') k++;
                if (grid[n - i - 1][n - j - 1] == '1') k++;
                if (grid[n - j - 1][i] == '1') k++;
                if (k >= 2) {
                    ans[j][n - i - 1] = ans[n - i - 1][n - j - 1] = ans[n - j - 1][i] = '1';
                } else {
                    ans[i][j] = '0';
                    ans[j][n - i - 1] = ans[n - i - 1][n - j - 1] = ans[n - j - 1][i] = '0';
                }
            } else {
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res += ans[i][j] != grid[i][j];
        }
    }
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

