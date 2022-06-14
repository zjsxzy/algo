#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};
void solve() {
    vector<string> chess(8);
    for (int i = 0; i < 8; i++) cin >> chess[i];
    int mx = 0, x, y;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i][j] != '#') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii >= 0 && ii < 8 && jj >= 0 && jj < 8 && chess[ii][jj] == '#') cnt++;
            }
            if (cnt > mx) {
                mx = cnt;
                x = i;
                y = j;
            }
        }
    }
    cout << x + 1 << ' ' << y + 1 << endl;
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

