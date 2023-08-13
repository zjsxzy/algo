#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


void solve() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> a(n);
    for (auto& x: a) cin >> x, sum += x;
    if (m > sum) {
        cout << 0 << endl;
        return;
    }
    int res = 0;
    function<void(int, int)> dfs = [&](int i, int s) {
        if (i == n && s == m) {
            res++;
            return;
        }
        for (int x = 1; x <= a[i]; x++) {
            dfs(i + 1, s + x);
        }
    };
    dfs(0, 0);
    cout << res << endl;
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