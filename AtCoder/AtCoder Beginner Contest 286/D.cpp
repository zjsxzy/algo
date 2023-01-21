#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (!dp[i][j]) continue;
            for (int k = 0; k <= B[i]; k++) {
                if (j + k * A[i] <= x) {
                    dp[i + 1][j + k * A[i]] = 1;
                }
            }
        }
    }
    if (dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}