#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (int i = 1; i < n; i++) {
        b[i] = (a[i] * 2 > a[i - 1]);
    }
    int curr = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            curr = 0;
        } else {
            curr++;
            if (curr >= k) res++;
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

