#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> s(m);
    s[0] = a[0];
    for (int i = 1; i < m; i++) s[i] = (s[i - 1] + a[i]) % n;
    int sum = s[m - 1];
    vector<LL> dist(n, 1e13);
    int val = 0, cnt = 0;
    while (dist[val] > cnt) {
        dist[val] = cnt;
        val = (val + sum) % n;
        cnt++;
    }
    LL res = 1e18;
    for (int i = 0; i < m; i++) {
        res = min(res, (LL)(i + 1) + m * dist[(2 * n - s[i] - x) % n]);
    }
    if (res >= 1e13) {
        cout << -1 << endl;
        return;
    }
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