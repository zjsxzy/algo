#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    LL sum = 0;
    multiset<int> st;
    for (auto& x: a) {
        cin >> x;
        sum += x;
        st.insert(x);
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        st.extract(x);
        auto y = *st.rbegin();
        if ((sum - 1) % 2 == 0) {
            if (y <= sum - 1 - y) cout << 1 << ' ';
            else cout << 0 << ' ';
        } else {
            if (x > 1 && y <= sum - 2 - y) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        st.insert(x);
    }
    cout << endl;
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