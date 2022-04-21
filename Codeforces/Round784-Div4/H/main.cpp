#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> bit(31);
    for (auto& x: a) {
        cin >> x;
        for (int j = 0; j < 31; j++) {
            if (x & (1 << j)) {
                bit[j]++;
            }
        }
    }
    int res = 0;
    for (int j = 30; j >= 0; j--) {
        if (n - bit[j] <= k) {
            res += (1 << j);
            k -= (n - bit[j]);
        }
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

