#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, x, y;

LL dfs(char color, int level, LL num) {
    if (color == 'r') {
        if (level == 1) return 0;
        else return dfs('r', level - 1, num) + dfs('b', level, num * x);
    } else {
        if (level == 1) return num;
        else return dfs('r', level - 1, num) + dfs('b', level - 1, num * y);
    }
}

void solve() {
    cin >> n >> x >> y;
    LL res = dfs('r', n, 1);
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

