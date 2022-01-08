#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL k;
    cin >> k;
    vector<int> bit;
    for (int i = 0; i < 63; i++) {
        if (k & (1L << i)) {
            bit.push_back(2);
        } else {
            bit.push_back(0);
        }
    }
    reverse(bit.begin(), bit.end());
    bool flag = false;
    for (int i = 0; i < 63; i++) {
        if (bit[i]) {
            flag = true;
        }
        if (flag) {
            cout << bit[i];
        }
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

