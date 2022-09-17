#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, int> idx;
    for (int i = 0; i < n; i++) {
        idx[{x[i], y[i]}] = 0;
    }
    int res = 0;
    vector<int> dx = {-1, -1, 0, 0, 1, 1};
    vector<int> dy = {-1, 0, -1, 1, 0, 1};
    for (int i = 0; i < n; i++) {
        if (idx[{x[i], y[i]}] > 0) continue;
        queue<pair<int, int>> q;
        q.push({x[i], y[i]});
        idx[{x[i], y[i]}] = ++res;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 6; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (idx.find({nx, ny}) != idx.end() && idx[{nx, ny}] == 0) {
                    idx[{nx, ny}] = res;
                    q.push({nx, ny});
                }
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

