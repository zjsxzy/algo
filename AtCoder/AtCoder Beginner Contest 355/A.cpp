#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b;
    set<int> st;
    cin >> a >> b;
    st.insert(a); st.insert(b);
    if (st.size() != 2) cout << -1 << endl;
    else {
        for (int i = 1; i <= 3; i++) {
            if (!st.count(i)) {
                cout << i << endl;
                return;
            }
        }
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