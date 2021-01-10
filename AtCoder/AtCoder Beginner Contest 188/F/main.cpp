#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

map<pair<LL, LL>, LL> dp;

LL f(LL x, LL y) {
    pair t = {x, y};
    if (dp.find(t) != dp.end()) return dp[t];
    if (y <= x) {
        return dp[t] = x - y;
    }
    LL res = 1e18;
    if (y % 2 == 0) {
        res = min(res, y - x);
        res = min(res, 1 + f(x, y / 2));
    } else {
        res = min(res, 1 + f(x, y + 1));
        res = min(res, 1 + f(x, y - 1));
    }
    return dp[t] = res;
}

void solve() {
    LL x, y;
    cin >> x >> y;
    LL res = f(x, y);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

