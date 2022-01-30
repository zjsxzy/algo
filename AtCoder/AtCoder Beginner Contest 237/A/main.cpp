#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    if (n >= -(1LL << 31) && n <= (1LL << 31) - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

