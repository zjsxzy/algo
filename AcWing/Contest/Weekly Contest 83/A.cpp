#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto c: s) cnt[c - 'a']++;
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += (cnt[i] != 0);
    }
    if (res & 1) cout << "odd" << endl;
    else cout << "even" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}