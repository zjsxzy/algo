#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int g, n;
    cin >> g >> n;
    vector<tuple<int, int, int>> graze;
    for (int i = 0; i < g; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        graze.push_back(make_tuple(t, x, y));
    }
    sort(graze.begin(), graze.end());
    vector<tuple<int, int, int>> cow;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        cow.push_back(make_tuple(t, x, y));
    }
    auto dist = [&](LL x1, LL y1, LL x2, LL y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    auto reachable = [&](tuple<int, int, int> a, tuple<int, int, int> b) {
        return dist(get<1>(a), get<2>(a), get<1>(b), get<2>(b)) <= (LL)(get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b));
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        auto x = lower_bound(graze.begin(), graze.end(), cow[i]);
        if (x == graze.end()) x--;
        // cout << i << ' ' << get<1>(cow[i]) << ' ' << get<2>(cow[i]) << ' ' << get<0>(cow[i]) << endl;
        // cout << get<1>(*x) << ' ' << get<2>(*x) << ' ' << get<0>(*x) << endl;
        bool innocent = !reachable(*x, cow[i]);
        if (x != graze.begin()) {
            x--;
            innocent |= !reachable(*x, cow[i]);
        }
        // x++;
        // if (x != graze.end()) flag |= reachable(*x, cow[i]);
        // cout << i << ' ' << innocent << endl;
        res += innocent;
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}