#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<LL> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    vector<LL> add(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        add[x - 1] += y;
    }
    LL curr = t;
    for (int i = 0; i < n - 1; i++) {
        curr += add[i];
        curr -= a[i];
        if (curr <= 0) {
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

