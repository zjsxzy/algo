#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    LL neg = 0, res = 0;
    for (int i = 0; i < n; i++) {
        a[i] += neg;
        if (a[i] < 0) neg += a[i];
        else {
            if (i + 1 < n) a[i + 1] += a[i];
        }
    }
    cout << a[n - 1] << endl;
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