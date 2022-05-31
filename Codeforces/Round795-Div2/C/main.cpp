#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1' && s[n - 1] == '0' && n - 1 - i <= k) {
            swap(s[i], s[n - 1]);
            k -= n - 1 - i;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && s[0] == '0' && i <= k) {
            swap(s[i], s[0]);
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += stoi(s.substr(i, 2));
    }
    cout << res << '\n';
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

