#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL calc(LL x, LL cnt) {
    LL i = 0;
    while (cnt > 0) {
        i += x;
        LL y = i; 
        while (y % x == 0) {
            y /= x;
            cnt--;
        }
    }
    return i;
}

void solve() {
    LL K;
    cin >> K;
    LL res = 1;
    for (LL x = 2; x * x <= K; x++) {
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

