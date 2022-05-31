#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n);
    for (int i = n - 1, j = n - 1; i >= 0; ) {
        while (j >= 0 && s[i] == s[j]) {
            j--;
        }
        if (i - j == 1) {
            cout << -1 << '\n';
            return;
        }
        ans[j + 1] = i;
        for (int k = i; k > j + 1; k--) {
            ans[k] = k - 1;
        }
        i = j;
    }
    for (auto x: ans) cout << x + 1 << ' ';
    cout << '\n';
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

