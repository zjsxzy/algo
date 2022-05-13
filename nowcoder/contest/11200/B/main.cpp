#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
    vector<vector<int>> cnt(2 * n + 1, vector<int>(2 * m + 1));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            cnt[x[i] + x[j]][y[i] + y[j]]++;
            if (cnt[x[i] + x[j]][y[i] + y[j]] == 2) {
                printf("YES %.1f %.1f\n", (x[i] + x[j]) / 2.0, (y[i] + y[j]) / 2.0);
                return;
            }
        }
    }
    cout << "NO" << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

