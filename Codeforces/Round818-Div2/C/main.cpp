#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[p]) p = i;
    }
    int j = p, i = (j - 1 + n) % n, tot = 0;
    while (tot < n) {
        if (a[i] > b[i] || a[j] > b[j]) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] != b[i] && b[i] > b[j] + 1) {
            cout << "NO" << endl;
            return;
        }
        a[i] = b[i];
        tot++;
        j = i;
        i = (i - 1 + n) % n;
    }
    cout << "YES" << endl;
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

