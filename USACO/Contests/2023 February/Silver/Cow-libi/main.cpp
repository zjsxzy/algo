#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int g, n;
    cin >> g >> n;
    vector<int> vst(g);
    vector<tuple<int, int, int>> graze;
    for (int i = 0; i < g; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        graze.push_back(make_tuple(x, y, t));
    }
    vector<tuple<int, int, int>> cow;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        cow.push_back(make_tuple(x, y, t));
    }
    auto dist = [&](LL x1, LL y1, LL x2, LL y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < g; j++) {
            if (vst[j]) continue;
            LL dt = (LL)(get<2>(cow[i])) - get<2>(graze[j]);
            LL t2 = dt * dt;
            if (dist(get<0>(cow[i]), get<1>(cow[i]), get<0>(graze[j]), get<1>(graze[j])) <= t2) {
                vst[j] = true;
                flag = false;
                break;
            }
        }
        res += flag;
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