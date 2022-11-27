#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const double eps = 1e-5;
double A, B;

double Calc(double x) {
    return B * x + A / sqrt(1 + x);
}

void solve() {
    cin >> A >> B;
    LL Left, Right;
    LL mid, midmid;
    double mid_value, midmid_value;
    Left = 0; Right = 1e18;
    while (Right - Left >= 1) {
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = Calc(mid);
        midmid_value = Calc(midmid);
        // 假设求解最大极值.
        if (mid_value <= midmid_value) Right = midmid;
        else Left = mid;
    }
    LL X = (long long)(Left);
    if (Calc(X + 1) < Calc(X)) {
        double res = Calc(X + 1);
        printf("%.9f\n", res);
    } else {
        double res = Calc(X);
        printf("%.9f\n", res);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

