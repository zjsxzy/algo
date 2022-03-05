#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    LL fact = 1;
    vector<LL> val;
    for (int i = 2; i < 20; i++) {
        fact *= i;
        val.push_back(fact);
        if (fact > 1e12) break;
    }
    int sz = val.size();
    int res = INT_MAX;
    for (int i = 0; i < (1 << sz); i++) {
        LL sum = 0;
        for (int j = 0; j < sz; j++) {
            if (i & (1LL << j)) {
                sum += val[j];
            }
        }
        int t = __builtin_popcount(i) + __builtin_popcountll(n - sum);
        res = min(res, t);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

