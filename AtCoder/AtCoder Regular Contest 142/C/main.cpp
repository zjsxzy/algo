#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> d1(n + 1), d2(n + 1);
    auto query = [&](int u, int v) {
        cout << "? " << u << ' ' << v << endl;
        fflush(stdout);
        int d;
        cin >> d;
        return d;
    };
    for (int i = 3; i <= n; i++) {
        d1[i] = query(1, i);
    }
    for (int i = 3; i <= n; i++) {
        d2[i] = query(2, i);
    }
    int res = INT_MAX;
    for (int k = 3; k <= n; k++) {
        res = min(res, d1[k] + d2[k]);
    }
    if (res == 3) {
        vector<int> v;
        for (int k = 3; k <= n; k++) {
            if (d1[k] + d2[k] == res) v.push_back(k);
        }
        if (v.size() == 1) cout << "! 1" << endl;
        else {
            int d = query(v[0], v[1]);
            if (d >= 2) cout << "! 1" << endl;
            else cout << "! " << res << endl;
        }
    } else {
        cout << "! " << res << endl;
    }
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

