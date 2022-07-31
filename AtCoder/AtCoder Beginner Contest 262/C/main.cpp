#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (a[i] == i);
    }
    LL res = 0;
    res += sum * (sum - 1) / 2;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        if (a[a[i]] == i) {
            sum++;
        }
    }
    res += sum / 2;
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

