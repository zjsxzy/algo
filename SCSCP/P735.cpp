#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

// index from 0
struct Fenwick{
    using T = LL;
    vector<T> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, T val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
            tree[pos] %= mod;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
            ans %= mod;
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector<LL> num;
    for (int i = 0; i < (int)sum.size(); i++) {
        num.push_back(sum[i]);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    for (int i = 0; i < (int)sum.size(); i++) {
        sum[i] = lower_bound(num.begin(), num.end(), sum[i]) - num.begin();
    }
    Fenwick tree(num.size());

    vector<LL> dp(n);
    dp[0] = 1;
    tree.upd(sum[0], 1);
    for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= i; j++) {
            // if (sum[i] - sum[j - 1] >= 0) {
                // dp[i] += dp[j - 1];
                // dp[i] %= mod;
            // }
        // }
        // cout << i << ' ' << dp[i] << endl;
        dp[i] = tree.get(sum[i]);
        tree.upd(sum[i], dp[i]);
    }
    cout << dp[n] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}