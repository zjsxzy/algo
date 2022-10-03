#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        auto x = st.find(i);
        if (x != st.end()) {
            st.erase(x);
            cnt++;
        } else {
            cnt += 2;
        }
        if (cnt > n) {
            cout << i - 1 << endl;
            return;
        }
    }
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

