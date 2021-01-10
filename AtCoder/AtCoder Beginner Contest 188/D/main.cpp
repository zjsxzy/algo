#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL n, C;
    cin >> n >> C;
    vector<int> a(n), b(n), c(n);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        vec.push_back({a[i], c[i]});
        vec.push_back({b[i] + 1, -c[i]});
    }
    sort(vec.begin(), vec.end());
    map<LL, LL> cost;
    LL cur = 0;
    for (auto &p : vec) {
        cur += p.second;
        cost[p.first] = cur;
    }

    LL res = 0, prev = 0, co = 0;
    for (auto &[k, v] : cost) {
        if (prev != 0) {
            res += (k - prev) * co;
        }
        prev = k;
        co = min(v, C);
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

