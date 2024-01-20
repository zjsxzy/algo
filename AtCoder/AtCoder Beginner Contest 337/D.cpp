#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H), T(W);
    for (int i = 0; i < H; i++) cin >> S[i];
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            T[j] += S[i][j];
        }
    }
    auto calc = [&](string s) {
        int n = s.size(), ans = 1e6;
        vector<int> sum(n + 1), block(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (s[i] == 'o');
            block[i + 1] = block[i] + (s[i] == 'x');
        }
        for (int i = 1; i + K - 1 <= n; i++) {
            if (block[i + K - 1] - block[i - 1] != 0) continue;
            ans = min(ans, K - (sum[i + K - 1] - sum[i - 1]));
        }
        return ans;
    };
    int res = 1e6;
    for (int i = 0; i < H; i++) {
        int t = calc(S[i]);
        res = min(res, t);
    }
    for (int j = 0; j < W; j++) {
        int t = calc(T[j]);
        res = min(res, t);
    }
    if (res == 1e6) cout << -1 << endl;
    else cout << res << endl;
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