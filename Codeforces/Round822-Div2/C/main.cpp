#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string T;
    cin >> T;
    T = '#' + T;
    LL res = 0;
    vector<vector<int>> fac(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            fac[j].push_back(i);
        }
    }
    vector<int> vst(n + 1);
    for (int i = 1; i <= n; i++) {
        if (T[i] == '1') {
            for (auto x: fac[i]) {
                if (!vst[x]) vst[x] = 1;
            }
        } else {
            for (auto x: fac[i]) {
                if (!vst[x]) {
                    res += x;
                    break;
                }
            }
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

