#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < 10; i++) {
        char c = i + '0';
        set<int> st;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                if (s[j][k] == c) {
                    int x = k;
                    while (st.find(x) != st.end()) {
                        x += 10;
                    }
                    st.insert(x);
                }
            }
        }
        int mx = 0;
        for (auto x: st) mx = max(mx, x);
        res = min(res, mx);
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

