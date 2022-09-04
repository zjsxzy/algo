#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int res = 0;
    while (st.size() != 1) {
        auto x = st.begin();
        auto y = st.end();
        y--;
        if (*y % *x != 0) {
            st.insert(*y % *x);
        }
        st.erase(y);
        res++;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

