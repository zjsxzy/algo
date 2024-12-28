#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<string> lan = {"", "l", "la", "lan", "lanq", "lanqi", "lanqio", "lanqiob", "lanqiobe"};
    auto calc = [&](string& s) {
        vector<int> vst(26);
        int sum = 0, sz = s.size();
        for (int i = 0; i < sz; i++) {
            char c = s[i];
            if (vst[c - 'a']) return 0;
            sum += c - 'a' + 1;
            if (c == 'l') {
                for (int l = 8; l >= 1; l--) {
                    if (i + l > sz) continue;
                    if (s.substr(i, l) == lan[l]) {
                        sum += l * 10;
                        break;
                    }
                }
            }
            vst[c - 'a'] = 1;
        }
        return sum;
    };
    int res = 0;
    string s;
    for (int i = 0; i < n; i++) {
        for (int l = 1; l <= 26; l++) {
            if (i + l > n) continue;
            string sub = S.substr(i, l);
            int t = calc(sub);
            // cout << sub << ' ' << t << '\n';
            if (t > res || (t == res && sub < s)) {
                res = t;
                s = sub;
            }
        }
    }
    cout << s << '\n';
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