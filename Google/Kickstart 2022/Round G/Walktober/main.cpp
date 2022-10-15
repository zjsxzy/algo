#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int m, n, p;
    cin >> m >> n >> p;
    p--;
    vector<vector<int>> s(m, vector<int>(n));
    vector<int> mx(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            mx[j] = max(mx[j], s[i][j]);
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        res += mx[j] - s[p][j];
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

