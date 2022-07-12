#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> st;
    for (auto& x: s) {
        cin >> x;
        st.insert(x);
    }
    for (auto x: s) {
        int m = x.size();
        bool find = false;
        for (int i = 1; i < m; i++) {
            string a = x.substr(0, i), b = x.substr(i, m - i);
            if (st.find(a) != st.end() && st.find(b) != st.end()) {
                find = true;
                break;
            }
        }
        if (find) cout << 1;
        else cout << 0;
    }
    cout << endl;
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

