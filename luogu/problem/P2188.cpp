#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, k;
vector<int> num;
LL dp[25][10][2][2];

LL dfs(int pos, int last, bool limit, bool lead) {
    if (pos == n) return 1;
    if (dp[pos][last][limit][lead] != -1) return dp[pos][last][limit][lead];
    LL res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (!lead && abs(v - last) > k) continue;
        if (lead && v == 0) {
            res += dfs(pos + 1, 11, limit && (v == num[pos]), true);
        } else {
            res += dfs(pos + 1, v, limit && (v == num[pos]), false);
        }
    }
    return dp[pos][last][limit][lead] = res;
}
    
LL calc(LL x) {
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    n = num.size();
    reverse(num.begin(), num.end());
    LL res = dfs(0, 11, true, true);
    return res;
}

void solve() {
    LL l, r;
    cin >> l >> r >> k;
    cout << calc(r) - calc(l - 1) << endl;
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