#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int x, k;
    scanf("%d %d\n", &x, &k);
    printf("%d %lld\n", 2 * x, lcm((long long)k * x - 1, (long long)k * x));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    scanf("%d", &ts);
    while (ts--) {
        solve();
    }
    return 0;
}


