#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, K;
    cin >> n >> K;
    vector<LL> t(n + 1), y(n + 1);
    t[0] = 1; y[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> y[i];
    }

    int curr = 0;
    LL add = 0, neg = 0;
    LL res = -(1LL << 60);
    multiset<LL> val;
    for (int i = n; i >= 0; i--) {
        if (t[i] == 1) {
            res = max(res, y[i] + add);
            curr++;
        } else {
            if (y[i] >= 0) add += y[i];
            else {
                val.insert(y[i]);
            }
        }
        if (curr > K) break;
        while (val.size() > K - curr) {
            auto x = val.end();
            x--;
            add += *x;
            val.erase(x);
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

