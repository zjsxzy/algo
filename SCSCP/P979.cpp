#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> sum(n + 1);
    string s;
    cin >> s;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            sum[i + 1] = sum[i] - 1;
            dp[i + 1] = dp[i] + 1;
        } else {
            sum[i + 1] = sum[i] + 1;
            dp[i + 1] = dp[i];
        }
    }
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // cout << endl;
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {0, 0}});
    for (int i = 1; i <= n; i++) {
        // for (int j = i; j >= 1 && i - j + 1 <= d; j--) {
        //     if (sum[i] > sum[j - 1]) dp[i] = min(dp[i], dp[j - 1]);
        //     else dp[i] = min(dp[i], dp[j - 1] + 1);
        // }
        auto x = *st.begin();
        if (sum[i] > x.second.first) dp[i] = min(dp[i], x.first);
        else dp[i] = min(dp[i], x.first + 1);
        // cout << i << ' ' << dp[i] << endl;
        st.insert({dp[i], {sum[i], i}});
        if (i - d >= 0) {
            st.erase({dp[i - d], {sum[i - d], i - d}});
        }
    }
    cout << dp[n] << endl;
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