#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c: s) cnt[c]++;
    for (auto [k, v]: cnt) {
        if (v == 1) {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
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

