#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    s += '#';
    t += '#';
    vector<pair<char, int>> cs, ct;
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != c) {
            cs.push_back({c, cnt});
            c = s[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    c = t[0];
    cnt = 1;
    for (int i = 1; i < (int)t.size(); i++) {
        if (t[i] != c) {
            ct.push_back({c, cnt});
            c = t[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if ((int)cs.size() != (int)ct.size()) {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < (int)cs.size(); i++) {
        if (cs[i].first != ct[i].first) {
            cout << "No" << endl;
            return;
        }
        if (cs[i].second > ct[i].second || (cs[i].second == 1 && ct[i].second > 1)) {
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

