#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(5 * n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = n; i < 4 * n; i++) {
        sum += a[i];
    }
    double res = (double)sum / 3 / n;
    // cout << res << endl;
    printf("%.9f\n", res);
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