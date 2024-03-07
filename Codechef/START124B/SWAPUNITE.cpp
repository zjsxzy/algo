#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    int res = INT_MAX;
    for (auto [k, sz]: cnt) {
        int mx = 0;
        int i = 0, tot = 0;
        for (; i < sz; i++) {
            tot += (s[i] == k);
        }
        mx = max(mx, tot);
        for (; i < n; i++) {
            tot -= (s[i - sz] == k);
            tot += (s[i] == k);
            mx = max(mx, tot);
        }
        res = min(res, sz - mx);
    }
    cout << res << endl;
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