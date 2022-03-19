#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL l, r;
    cin >> l >> r;
    pair<LL, LL> p = {l, r};
    queue<pair<LL, LL>> q;
    q.push(p);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (gcd(t.first, t.second) == 1) {
            cout << t.second - t.first << endl;
            return;
        }
        q.push({t.first + 1, t.second});
        q.push({t.first, t.second - 1});
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

