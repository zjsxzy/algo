#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    set<int> st;
    for (int i = n - 1; i >= 0; i--) {
        if (st.find(a[i]) == st.end()) {
            st.insert(a[i]);
        } else {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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

