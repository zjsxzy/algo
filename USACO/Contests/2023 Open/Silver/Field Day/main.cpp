#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, c;
    cin >> c >> n;
    set<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'G') a[i] |= (1 << j);
        }
        st.insert(a[i]);
    }
    map<int, int> ans;
    for (auto x: st) {
        int res = 0;
        for (auto y: st) {
            res = max(res, __builtin_popcount(x ^ y));
        }
        ans[x] = res;
    }
    for (int i = 0; i < n; i++) cout << ans[a[i]] << endl;
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