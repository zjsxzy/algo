#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, int> ms, mt;
    string a = "atcoder";
    for (auto c: a) {
        ms[c] = 0;
        mt[c] = 0;
    }
    ms['@'] = 0;
    mt['@'] = 0;
    for (auto c: s) {
        ms[c]++;
    }
    for (auto c: t) {
        mt[c]++;
    }
    
    for (auto [c, v]: mt) {
        if (c == '@') continue;
        if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r') {
            if (ms[c] < mt[c]) {
                ms['@'] -= mt[c] - ms[c];
                ms[c] += mt[c] - ms[c];
            } else {
                mt['@'] -= ms[c] - mt[c];
                mt[c] += ms[c] - mt[c];
            }
        } else {
            if (ms.find(c) == ms.end() || v != ms[c]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    if (ms['@'] != mt['@'] || ms['@'] < 0 || mt['@'] < 0) cout << "No" << endl;
    else cout << "Yes" << endl;
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