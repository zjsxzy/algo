#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        w[i] += w[i - 1];
        v[i] += v[i - 1];
    }
    vector<int> dp(M + 1);
    for (int i = 1; i <= K; i++) {
        for (int j = K; j <= N; j++) {
            int weight = w[j] - w[i - 1], value = v[j] - v[i - 1];
            for (int k = weight; k <= M; k++) {
                dp[k] = max(dp[k], dp[k - weight] + value);
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << dp[i];
        if (i == M) cout << endl;
        else cout << ' ';
    }
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