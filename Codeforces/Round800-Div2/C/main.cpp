#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n), s(n + 1);
    for (auto& x: a) cin >> x;
    s[0] = 0;
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
    if (n == 1) {
        if (a[0] == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        int p = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] < 0) {
                cout << "No" << endl;
                return;
            }
            if (s[i] == 0) {
                p = i;
                break;
            }
        }
        for (int i = p + 1; i <= n; i++) {
            if (s[i] != 0) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
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

