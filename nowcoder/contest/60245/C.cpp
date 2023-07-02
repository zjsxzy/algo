#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL calc(string s, string t) {
    // cout << s << ' ' << t;
    LL res = 0;
    int n = s.size();
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '0') continue;
        while (j < n && t[j] == '0') j++;
        // cout << i << ' ' << j << endl;
        res += abs(i - j);
        j++;
    }
    // cout << ' ' << res << endl;
    return res;
}

void solve() {
    string s;
    std::cin >> s;
    int n = s.size();
    int zero = 0, one = 0;
    for (auto c: s) {
        if (c == '1') one++;
        else zero++;
    }
    string t;
    if (zero != one) {
        if (zero > one) {
            for (int j = 0; j < n / 2; j++) t += "01";
            t += '0';
        } else {
            for (int j = 0; j < n / 2; j++) t += "10";
            t += '1';
        }
        LL res = calc(s, t);
        std::cout << res << endl;
    } else {
        for (int j = 0; j < n / 2; j++) t += "01";
        LL res = calc(s, t);
        t = "";
        for (int j = 0; j < n / 2; j++) t += "10";
        res = min(res, calc(s, t));
        std::cout << res << endl;
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