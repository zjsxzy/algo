#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> st;
    int res = 0;
    for (auto c: s) {
        if (st.find(c) == st.end()) {
            res += 2;
        } else {
            res++;
        }
        st.insert(c);
    }
    cout << res << endl;
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

