#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> num;
int n;
long long dp[16][155][2][2];

long long dfs(int pos, int sum, bool limit, bool lead) {
    if (pos == n) return sum;
    if (dp[pos][sum][limit][lead] != -1) return dp[pos][sum][limit][lead];
    long long res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (lead && v == 0) {
            res += dfs(pos + 1, sum + v, limit && (v == num[pos]), true);
        } else {
            res += dfs(pos + 1, sum + v, limit && (v == num[pos]), false);
        }
    }
    return dp[pos][sum][limit][lead] = res;
}

long long f(long long x) {
    if (x == -1) return 0;
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    n = num.size();
    long long res = dfs(0, 0, true, true);
    return res;
}

void solve() {
    long long a, b;
    cin >> a >> b;
    cout << f(b) - f(a - 1) << endl;
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