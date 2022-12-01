#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j - a[i] >= 0 && dp[j - a[i]]) dp[j] = 1;
        }
    }
    vector<int> ans;
    for (int j = 1; j <= sum; j++) {
        if (dp[j]) ans.push_back(j);
    }
    cout << (int)ans.size() << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

