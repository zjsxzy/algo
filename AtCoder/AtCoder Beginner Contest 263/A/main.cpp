#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    map<int, int> cnt;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (auto [k, v]: cnt) {
        if (v != 2 && v != 3) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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

