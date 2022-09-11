#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while (i < n && s[i] == 'd') i++;
    if (i == n) {
        cout << s << endl;
        return;
    }
    string res = s;
    for (int j = i; j < n; j++) {
        string t = s;
        reverse(t.begin() + i, t.begin() + j + 1);
        for (int k = i; k <= j; k++) {
            t[k] = (t[k] == 'd') ? 'p' : 'd';
        }
        res = min(res, t);
    }
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

