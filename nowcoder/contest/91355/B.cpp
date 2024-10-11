#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    double a;
    cin >> a;
    double res = (a + sqrt(a * a + 4)) / 2;
    printf("%.15f\n", res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}