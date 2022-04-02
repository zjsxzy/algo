#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    map<int, int> mx, my;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }
    for (auto& [k, v]: mx) {
        if (v == 1) cout << k << " ";
    }
    for (auto& [k, v]: my) {
        if (v == 1) cout << k << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

