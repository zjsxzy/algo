#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
int a, b, n;
string c;
vector<int> num;
int dp[500][100][300][2][2];

int dfs(int pos, int m, int sum, bool limit, bool lead) {
    if (pos == n) {
        if (m == 0) {
            return sum;
        } else {
            return 0;
        }
    }
    if (dp[pos][m][sum][limit][lead] != -1) return dp[pos][m][sum][limit][lead];
    int res = 0;
    for (int v = 0; v <= (limit ? num[pos] : b - 1); v++) {
        if (lead && v == 0) {
            res += dfs(pos + 1, (m * b + v) % a, sum + v, limit && (v == num[pos]), true);
            res %= mod;
        } else {
            res += dfs(pos + 1, (m * b + v) % a, sum + v, limit && (v == num[pos]), false);
            res %= mod;
        }
    }
    return dp[pos][m][sum][limit][lead] = res;
}

void solve() {
    cin >> a >> b;
    cin >> c;
    for (auto x: c) num.push_back(x - '0');
    n = num.size();
    memset(dp, -1, sizeof(dp));
    int res = dfs(0, 0, 0, true, true);
    cout << res << endl;
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