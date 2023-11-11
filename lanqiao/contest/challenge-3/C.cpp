#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, int> mp;
    if (s[0] == s[1] || s == "MF" || s == "FM") cout << "ShallowDream" << endl;
    else {
        for (int i = 3; i <= 9; i++) {
            mp['0' + i] = i;
        }
        mp['X'] = 10; mp['J'] = 11; mp['Q'] = 12; mp['K'] = 13;
        mp['A'] = 14; mp['2'] = 15; mp['M'] = 16, mp['F'] = 17;
        if (t == "MF" || t == "FM") cout << "Joker" << endl;
        else if (mp[s[0]] >= mp[t[0]] && mp[s[0]] >= mp[t[1]]) cout << "ShallowDream" << endl;
        else if (mp[s[1]] >= mp[t[0]] && mp[s[1]] >= mp[t[1]]) cout << "ShallowDream" << endl;
        else cout << "Joker" << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}