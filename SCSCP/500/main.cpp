#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

LL n, m, q, g;

LL calc(LL bound) {

}

void solve() {
    cin >> n >> m >> q;
    g = gcd(n, m);
    LL bound = n * m / g;
    LL sum;
    if (q <= bound) {
        sum = calc(q);
    } else {
        sum = calc(bound);
        sum += q / g - (bound / g);
    }
    cout << q - sum << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}
