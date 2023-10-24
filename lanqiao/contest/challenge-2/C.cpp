#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& x: h) cin >> x;
    LL sum = 0;
    vector<int> diff;
    for (int i = 1; i < n; i++) {
        sum += h[i] - h[i - 1];
        diff.push_back(h[i] - h[i - 1]);
    }
    sort(diff.rbegin(), diff.rend());
    for (int i = 0; i < k - 1; i++) {
        sum -= diff[i];
    }
    cout << sum << endl;
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