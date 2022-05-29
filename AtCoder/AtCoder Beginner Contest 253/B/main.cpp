#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x: s) cin >> x;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'o') {
                pos.emplace_back(i, j);
            }
        }
    }
    cout << abs(pos[0].first - pos[1].first) + abs(pos[0].second - pos[1].second) << endl;
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

