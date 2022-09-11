#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if ((int)a.size() == 1) {
        cout << 1 << endl;
        return;
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
    int g = b[0];
    for (int i = 1; i < n - 1; i++) g = gcd(g, b[i]);
    if (g > 1) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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

