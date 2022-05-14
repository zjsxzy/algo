#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<string, int> val, index;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        if (val.find(s) == val.end()) {
            val[s] = t;
            index[s] = i + 1;
        }
    }
    int mx = 0;
    string s;
    for (auto [k, v]: val) {
        if (v > mx) {
            mx = v;
            s = k;
        }
    }
    cout << index[s] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

