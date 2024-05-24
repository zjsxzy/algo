#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    if (n == 1) {
        cout << 0 << endl;
    } else {
        multiset<int> st;
        for (auto x: a) st.insert(x);
        LL res = *st.rbegin() - *st.begin();
        LL sum = 0;
        for (int i = n - 1; i >= 1; i--) {
            sum += a[i];
            st.extract(a[i]);
            res = max(res, sum - *st.begin());
        }

        st.clear();
        for (auto x: a) st.insert(x);
        sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += a[i];
            st.extract(a[i]);
            res = max(res, sum - *st.begin());
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