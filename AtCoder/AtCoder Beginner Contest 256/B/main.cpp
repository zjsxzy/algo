#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> p(4);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[0]++;
        vector<int> np(4);
        for (int i = 0; i < 4; i++) {
            if (i + x >= 4) {
                res += p[i];
            } else {
                np[i + x] = p[i];
            }
        }
        p = np;
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

