#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL a, s;
    cin >> a >> s;
    LL sum = 0;
    vector<int> bit(60);
    for (int i = 0; i < 60; i++) {
        if (a & (1LL << i)) {
            bit[i] = 1;
            sum += (1LL << i) * 2LL;
        }
    }
    if (sum == s) {
        cout << "Yes" << endl;
    } else if (sum > s) {
        cout << "No" << endl;
    } else {
        LL rem = s - sum;
        for (int i = 0; i < 60; i++) {
            if ((rem & (1LL << i)) && (bit[i])) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
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

