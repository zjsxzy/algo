#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n = 9;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    set<set<pair<int, int>>> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int dx = -10; dx <= 10; dx++) {
                for (int dy = -10; dy <= 10; dy++) {
                    set<pair<int, int>> se;
                    se.insert({i, j});
                    se.emplace(i + dx, j + dy);
                    se.emplace(i + dx - dy, j + dy + dx);
                    se.emplace(i - dy, j + dx);
                    if (se.size() != 4) continue;
                    bool flag = true;
                    for (auto [x, y]: se) {
                        if (x < 0 || x >= n || y < 0 || y >= n || s[x][y] != '#') flag = false;
                    }
                    if (flag) {
                        st.insert(se);
                    }
                }
            }
        }
    }
    cout << (int)st.size() << endl;
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

