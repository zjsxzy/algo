#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    string s;
    cin >> n >> s;
    LL res = n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            res -= i;
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

