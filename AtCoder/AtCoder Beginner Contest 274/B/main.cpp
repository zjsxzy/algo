#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];
    for (int j = 0; j < w; j++) {
        int sum = 0;
        for (int i = 0; i < h; i++) {
            sum += grid[i][j] == '#';
        }
        cout << sum << ' ';
    }
    cout << endl;
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

