#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int r, a, b;
    cin >> r >> a >> b;

    int x = r;
    double area = M_PI * x * x;
    double res = area;

    while (x > 0) {
        x *= a;
        area = M_PI * x * x;
        res += area;

        x /= b;
        area = M_PI * x * x;
        res += area;
    }
    printf("%.6f\n", res);
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

