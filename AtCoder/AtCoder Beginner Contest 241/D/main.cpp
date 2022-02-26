#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    multiset<LL> st;
    while (q--) {
        int type;
        LL x;
        int k;
        cin >> type;
        if (type == 1) {
            cin >> x;
            st.insert(x);
        } else {
            cin >> x >> k;
            if (type == 2) {
                /*
                for (auto v: st) {
                    cout << v << " ";
                }
                cout << endl;
                */
                if (st.empty()) {
                    cout << -1 << endl;
                    continue;
                }
                auto it = st.upper_bound(x);
                if (it == st.end()) it--;
                vector<LL> val;
                if (it == st.begin()) {
                    if (*it <= x) {
                        val.push_back(*it);
                    }
                } else {
                    if (*it > x) it--;
                    while (it != st.begin() && (int)val.size() < k) {
                        val.push_back(*it);
                        it--;
                    }
                    if (it == st.begin()) val.push_back(*it);
                }
                if ((int)val.size() < k) {
                    cout << -1 << endl;
                } else {
                    cout << val[k - 1] << endl;
                }
            } else {
                if (st.empty()) {
                    cout << -1 << endl;
                    continue;
                }
                auto it = st.lower_bound(x);
                vector<LL> val;
                while (it != st.end() && (int)val.size() < k) {
                    val.push_back(*it);
                    it++;
                }
                if ((int)val.size() < k) {
                    cout << -1 << endl;
                } else {
                    cout << val[k - 1] << endl;
                }
            }
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

