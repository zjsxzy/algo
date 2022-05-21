#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL l;
    cin >> n >> l;
    multiset<LL> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l -= x;
        st.insert(x);
    }
    if (l > 0) st.insert(l);
    n = st.size();
    LL res = 0;
    for (int i = 0; i < n - 1; i++) {
        auto x = *st.begin(); st.erase(st.begin());
        auto y = *st.begin(); st.erase(st.begin());
        res += x + y;
        st.insert(x + y);
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

