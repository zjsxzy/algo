#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    map<int, int> cnt;
    set<int> st;
    int q;
    cin >> q;
    while (q--) {
        int type, x, c;
        cin >> type;
        if (type == 1) {
            cin >> x;
            cnt[x]++;
            st.insert(x);
        } else if (type == 2) {
            cin >> x >> c;
            int m = min(c, cnt[x]);
            cnt[x] -= m;
            if (cnt[x] == 0) {
                st.erase(x);
            }
        } else {
            auto mx = st.end(); mx--;
            cout << *mx - *st.begin() << endl;
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

