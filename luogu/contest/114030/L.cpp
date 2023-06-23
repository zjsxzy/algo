#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    multiset<LL> st;
    for (int i = 0; i < n; i++) {
        LL x;
        std::cin >> x;
        st.insert(x);
    }
    while (!st.empty()) {
        // for (auto x: st) cout << x << ' ';
        // cout << endl;
        auto l = *st.begin();
        auto r = *st.rbegin();
        if (r - r / 2 - l > 0) {
            st.extract(r);
            st.insert(r / 2);
            st.extract(l);
            st.insert(l * 2);
        } else {
            break;
        }
    }
    LL res = 0;
    for (auto x: st) res += x;
    map<int, int> cnt;
    cnt[2] = cnt[3] = 0;
    for (auto x: st) cnt[x]++;
    std::cout << res - min(cnt[2], cnt[3]) << endl;
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