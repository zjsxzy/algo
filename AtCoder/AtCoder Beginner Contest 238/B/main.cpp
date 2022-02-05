#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> seg;
    seg.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (auto& x: seg) {
            x += a[i];
        }
        seg.push_back(0);
    }
    for (auto& x: seg) {
        x %= 360;
    }
    sort(seg.begin(), seg.end());
    seg.push_back(360);
    int res = 0;
    for (int i = 1; i < seg.size(); i++) {
        res = max(res, seg[i] - seg[i - 1]);
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

