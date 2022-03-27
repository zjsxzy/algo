#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

LL f(LL a, LL b) {
    if (a > b) return 1e18;
    if (a * 2 > b) return b - a;
    if (b % 2 == 1) return f(a, b - 1) + 1;
    if (b % 2 == 0 && a <= b / 2) return f(a, b / 2) + 1;
    return 1e18;
}

void solve() {
    LL a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    LL res = 1e18, cnt1 = 0; // divide and plus
    while (a > 1) {
        LL cnt2 = f(a, b); // multiply and plus
        res = min(res, cnt1 + cnt2);
        if (a % 2 == 1) a++;
        else a /= 2;
        cnt1++;
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

