#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    set<pair<int, pair<int, int>>> st;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, c;
            cin >> x >> c;
            st.insert({i, {c, x}});
        } else {
            int c;
            cin >> c;
            LL tot = 0, sum = 0;
            while (!st.empty() && tot + st.begin()->second.first <= c) {
                tot += st.begin()->second.first;
                sum += (LL)st.begin()->second.second * st.begin()->second.first;
                st.erase(st.begin());
            }
            if (tot < c && !st.empty()) {
                auto x = st.begin();
                sum += (LL)x->second.second * (c - tot);
                st.insert({x->first, {x->second.first - (c - tot), x->second.second}});
                st.erase(x);
            }
            cout << sum << endl;
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}