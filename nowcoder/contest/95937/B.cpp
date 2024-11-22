#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<string, string> f(string s) {
    if (s.find('.') == -1) {
        return make_pair(s, "000000");
    } else {
        int p = s.find('.');
        string t = s.substr(p + 1, 6);
        if (t.size() < 6) {
            int sz = t.size();
            for (int i = 0; i < 6 - sz; i++) {
                t += '0';
            }
        }
        return make_pair(s.substr(0, p), t);
    }
}

void solve() {
    string a, b;
    cin >> a >> b;
    pair<string, string> s = f(a);
    pair<string, string> t = f(b);
    // cout << s.first << ' ' << s.second << ' ' << t.first << ' ' << t.second << endl;
    if (s == t) cout << "YES" << endl;
    else cout << "NO" << endl;
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