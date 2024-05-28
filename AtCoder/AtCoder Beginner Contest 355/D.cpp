#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vec.push_back({l, -1});
        vec.push_back({r, l});
    }
    sort(vec.begin(), vec.end());
    multiset<int> st;
    LL res = 0;
    for (auto v: vec) {
        int x = v.first, y = v.second;
        // cout << x << ' ' << y << endl;
        if (y == -1) {
            st.insert(x);
        } else {
            st.extract(y);
            res += st.size();
        }
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