#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cnt += x;
            cnt %= n;
        } else {
            x--;
            cout << s[(x - cnt + n) % n] << endl;
        }
    }
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

