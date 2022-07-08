#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> vst(n + 1);
    cout << 2 << endl;
    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int x = i;
            while (x <= n) {
                cout << x << ' ';
                vst[x] = 1;
                x *= 2;
            }
        }
    }
    cout << endl;
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

