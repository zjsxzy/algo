#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    unordered_map<LL, LL> f;
    f[0] = 1;
    function<LL(LL)> calc = [&](LL x) {
        if (f.count(x)) return f[x];
        return f[x] = calc(x / 2) + calc(x / 3);
    };
    cout << calc(n) << endl;
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

