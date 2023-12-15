#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXP = 50;
const LL MAXS = 1e18;

void solve() {
    LL x, y, z;
    cin >> x >> y >> z;
    set<LL> st;
    unsigned long long a = 1;
    for (int i = 0; i < MAXP; i++) {
        unsigned long long b = 1;
        for (int j = 0; j < MAXP; j++) {
            unsigned long long c = 1;
            for (int k = 0; k < MAXP; k++) {
                st.insert(a + b + c);
                c *= z;
                if (a + b + c > MAXS) break;
            }
            b *= y;
            if (a + b > MAXS) break;
        }
        a *= x;
        if (a > MAXS) break;
    }
    int q;
    cin >> q;
    while (q--) {
        LL S;
        cin >> S;
        auto it = st.upper_bound(S);
        while (*it == S + 1) {
            S = *it;
            it++;
        }
        cout << S + 1 << ' ' << *it - S - 1 << endl;
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