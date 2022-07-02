#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& x: a) cin >> x;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 8; d++) {
                string val;
                int x = i, y = j;
                val += a[x][y];
                for (int k = 0; k < n - 1; k++) {
                    x += dx[d];
                    y += dy[d];
                    if (x < 0) x += n;
                    if (y < 0) y += n;
                    if (x >= n) x -= n;
                    if (y >= n) y -= n;
                    val += a[x][y];
                }
                res = max(res, (LL)stol(val));
            }
        }
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

