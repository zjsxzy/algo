#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector s(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        int res = 0;
        map<int, int> cnt;
        for (int j = i; j <= n; j++) {
            cnt[a[j]]++;
            if (cnt[a[j]] > res) res = cnt[a[j]];
            s[i][j] = res;
        }
    }
    vector dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            for (int l = 1; l <= i; l++) {
                dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + s[l][i]);
            }
        }
    }
    cout << dp[n][k] << endl;
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