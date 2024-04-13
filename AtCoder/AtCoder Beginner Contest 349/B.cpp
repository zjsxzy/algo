#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c: s) cnt[c]++;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (auto [k, v]: cnt) {
            if (v == i) t++;
        }
        if (t == 1 || t > 2) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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