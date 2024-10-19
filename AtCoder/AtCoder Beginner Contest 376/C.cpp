#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> st;
    for (int i = 0; i < n - 1; i++) {
        int b;
        cin >> b;
        st.insert(-b);
    }
    sort(a.rbegin(), a.rend());
    int res = -1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto f = -*st.begin();
        // cout << x << ' ' << f << endl;
        if (f < x) {
            if (res != -1) {
                cout << -1 << endl;
                return;
            } else {
                res = x;
            }
        } else {
            st.extract(st.begin());
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