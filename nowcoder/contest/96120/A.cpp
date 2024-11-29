#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    double res = 0;
    if (n == 1) {
        res = 0;
    } else if (n == 2) {
        res = (a[0] + a[1]) * 0.5;
    } else {
        double sum = a[0] + a[1];
        for (int i = 2; i < n; i++) sum += 2 * a[i];
        res = sum * 0.5;
    }
    printf("%.2f\n", res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}