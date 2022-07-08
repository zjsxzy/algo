#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), s(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
        s[a[i]]++;
    }
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    auto mn = st.begin(), mx = st.end();
    mx--;
    while (*mx - *mn > 1) {
        st.insert(*mx - 1);
        st.insert(*mn + 2);
        st.erase(mn);
        st.erase(mx);
        mn = st.begin();
        mx = st.end();
        mx--;
    }
    cout << *mx << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}
