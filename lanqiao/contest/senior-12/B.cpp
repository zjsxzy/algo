#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> st;
    for (auto& x: a) {
        cin >> x;
        st.insert(x);
    }
    cout << (int)st.size() << ' ';
    if (n == m && st.size() == 1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
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