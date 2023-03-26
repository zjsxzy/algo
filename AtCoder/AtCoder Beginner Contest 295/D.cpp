#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> state(n + 1);
    vector<int> cnt(10, 0);
    map<vector<int>, LL> mp;
    mp[cnt]++;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
        cnt[s[i] - '0'] %= 2;
        mp[cnt]++;
    }
    LL res = 0;
    for (auto [k, v]: mp) {
        res += v * (v - 1) / 2;
    }
    cout << res << endl;
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