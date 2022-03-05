#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double res;
    if (x <= a) {
        res = 1.0;
    } else if (x > a && x <= b) {
        res = c * 1.0 / (b - a);
    } else {
        res = 0.0;
    }
    printf("%.6f\n", res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

