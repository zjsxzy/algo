#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> s[i];
    vector<int> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        a[i] = s[i - 1] - a[i - 1];
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

