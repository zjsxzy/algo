#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i < x; i++) {
        if (cnt[i] % (i + 1)) {
            cout << "No" << endl;
            return;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
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

