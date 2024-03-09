#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (auto& x: b) cin >> x;
    cin >> l;
    vector<int> c(l);
    for (auto& x: c) cin >> x;
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                st.insert(a[i] + b[j] + c[k]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (st.count(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
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