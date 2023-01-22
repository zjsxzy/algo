#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> cnt(26);
    for (auto c: s) cnt[c - 'a']++;
    for (auto c: t) cnt[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            cout << -1 << endl;
            return;
        }
    }
    int res = n;
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        if (s[j] == t[i]) {
            j--;
            res--;
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}