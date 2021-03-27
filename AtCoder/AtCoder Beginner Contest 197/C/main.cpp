#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int res = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (!((mask >> (n - 1)) & 1)) continue;
        int temp = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt |= a[i];
            if ((mask >> i) & 1) {
                temp ^= cnt;
                cnt = 0;
            }
        }
        //cout << mask << " " << temp << endl;
        if (temp < res) res = temp;
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

