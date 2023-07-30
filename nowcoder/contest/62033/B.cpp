#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    for (int j = 0, i = n - k + 1; i <= n; i++, j += 2) {
        ans[j] = i;
    }
    for (int i = 1, j = 0; j < n; j++) {
        if (!ans[j]) {
            ans[j] = i++;
        }
    }
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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