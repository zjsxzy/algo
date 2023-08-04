#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<int> num;
int dp[15][10][2][2];

int dfs(int pos, int last, bool limit, bool lead) {
    if (pos == n) return 1;
    if (dp[pos][last][limit][lead] != -1) return dp[pos][last][limit][lead];
    int res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (!lead && abs(v - last) != 1) continue;
        if (lead && v == 0) {
            res += dfs(pos + 1, 11, limit && (v == num[pos]), true);
        } else {
            res += dfs(pos + 1, v, limit && (v == num[pos]), false);
        }
    }
    return dp[pos][last][limit][lead] = res;
}
    
int f(int x) {
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    n = num.size();
    int res = dfs(0, 11, true, true);
    return max(0, res - 10);
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}