#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL x;
    cin >> x;
    set<LL> st;
    for (int i = 1; i < 10; i++) {
        st.insert(i);
    }
    queue<LL> q;
    for (int i = 10; i < 100; i++) {
        st.insert(i);
        q.push(i);
    }
    while (!q.empty()) {
        LL t = q.front(); q.pop();
        int d0 = t % 10, d1 = t % 100 / 10;
        int d = d0 - d1;
        int next_d = d0 + d;
        if (next_d >= 0 && next_d <= 9) {
            LL val = t * 10 + next_d;
            if (val <= 1e18) {
                st.insert(val);
                q.push(val);
            }
        }
    }
    auto res = st.lower_bound(x);
    cout << *res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

