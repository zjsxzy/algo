#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), d(n), idx(n);
    for (auto& x: a) cin >> x;
    for (auto& x: d) cin >> x;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    int rest = n - 1;
    LL res = 0;
    for (auto i: idx) {
        if (d[i] < rest) {
            res += (LL)d[i] * a[i];
            rest -= d[i];
        } else {
            res += (LL)rest * a[i];
            break;
        }
    }
    cout << res << '\n';
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