#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<string, int> calc(vector<string>& s) {
    int n = s.size(), m = s[0].size();
    map<string, int> res;
    for (int j = 0; j < m; j++) {
        string p;
        for (int i = 0; i < n; i++) {
            p += s[i][j];
        }
        res[p]++;
    }
    return res;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h), t(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    map<string, int> cnts = calc(s);
    for (int i = 0; i < h; i++) {
        cin >> t[i];
    }
    map<string, int> cntt = calc(t);
    for (auto [k, v]: cnts) {
        if (cntt.find(k) == cntt.end() || v != cntt[k]) {
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

