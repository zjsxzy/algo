#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    ll x = stoll(s);
    int n = s.size();
    ll res = -1;
    if (n > 2) {
        string t;
        for (int i = 0; i < n - 1; i++) t += '9';
        res = stoll(t);
    }
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            string p = s.substr(0, i);
            string t;
            for (int j = 0; j < n / i; j++) t += p;
            ll val = stoll(t);
            if (val <= x && val > res) res = val;

            if (i > 0) {
                p = to_string(stoll(s.substr(0, i)) - 1);
                t = "";
                for (int j = 0; j < n / i; j++) t += p;
                val = stoll(t);
                if (val <= x && val > res) res = val;
            }
        }
    }
    cout << res << endl;
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
