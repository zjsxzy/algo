#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (cnt.find(s) != cnt.end()) {
            cnt[s]++;
        } else if (cnt.find(rs) != cnt.end()) {
            cnt[rs]++;
        } else {
            cnt[s]++;
        }
    }
    int res = 0;
    for (auto [k, v]: cnt) {
        res++;
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