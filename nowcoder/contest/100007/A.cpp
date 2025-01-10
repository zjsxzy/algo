#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    map<string, set<string>> mp;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            string a, b;
            cin >> a >> b;
            mp[a].insert(b);
        } else if (op == 2) {
            string s;
            cin >> s;
            if (!mp.count(s)) cout << 0 << '\n';
            else cout << (int)mp[s].size() << '\n';
        } else if (op == 3) {
            string a, b;
            cin >> a >> b;
            if (!mp.count(a)) cout << 0 << '\n';
            else {
                if (mp[a].find(b) == mp[a].end()) cout << 0 << '\n';
                else cout << 1 << '\n';
            }
        } else {
            cout << (int)mp.size() << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}