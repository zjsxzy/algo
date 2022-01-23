#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> st(n);
    for (auto& x: st) {
        cin >> x;
    }
    set<string> express;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        express.insert(s);
    }
    for (auto& x: st) {
        if (express.find(x) == express.end()) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

