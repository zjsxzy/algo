#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> A(n);
    LL res = 0;
    multiset<int> st, st2;
    for (int i = 0; i < k; i++) st.insert(0);
    for (int i = k; i < n; i++) st2.insert(0);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;

        if (st.find(A[x]) != st.end()) {
            st.extract(A[x]);
            res -= A[x];
            if (!st2.empty() && *st2.rbegin() > y) {
                int val = *st2.rbegin();
                st2.extract(val);
                st2.insert(y);
                st.insert(val);
                res += val;
            } else {
                st.insert(y);
                res += y;
            }
        } else {
            st2.extract(A[x]);
            if (!st.empty() && y > *st.begin()) {
                int val = *st.begin();
                st.extract(val);
                res -= val;
                st.insert(y);
                res += y;
                st2.insert(val);
            } else {
                st2.insert(y);
            }
        }

        A[x] = y;
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