#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        map<int, int> cnt;
        for (int i = l; i <= r; i++) cnt[c[i]]++;
        vector<int> vec;
        for (auto [k, v]: cnt) vec.push_back(v);
        sort(vec.rbegin(), vec.rend());
        LL res = 0;
        for (int i = 0, p = 1; i < vec.size(); i++, p++) {
            res += (LL)vec[i] * p;
        }
        cout << res << endl;
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