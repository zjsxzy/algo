#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto& x: p) {
        cin >> x;
    }
    set<int> st;
    for (int i = 0; i < k; i++) {
        st.insert(p[i]);
    }
    for (int i = k; i <= n; i++) {
        auto it = st.begin();
        cout << *it << endl;
        if (p[i] > *it) {
            st.erase(it);
            st.insert(p[i]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

