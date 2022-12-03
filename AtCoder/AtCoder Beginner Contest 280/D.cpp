#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL calc(LL x, LL cnt) {
    LL i = x, sum = 1;
    for (; sum < cnt; i += x) {
        LL y = i; 
        while (y % x == 0) {
            y /= x;
            sum++;
        }
    }
    return i;
}

void solve() {
    LL K;
    cin >> K;
    LL res = 1;
    for (LL x = 2; x <= sqrt(K); x++) {
        if (K % x != 0) continue;
        LL tot = 0;
        while (K % x == 0) {
            K /= x;
            tot++;
        }
        // cout << x << ' ' << tot << ' ' << calc(x, tot) << endl;
        res = max(res, calc(x, tot));
    }
    res = max(res, K);
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

