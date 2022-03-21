#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 15;
vector<int> num;
int n;
int dp[maxn][maxn][2][2];

int dfs(int pos, int last, bool limit, bool lead) {
    if (pos == n) return 1;
    if (dp[pos][last][limit][lead] != -1) return dp[pos][last][limit][lead];
    int res = 0;
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (abs(v - last) < 2) continue;
        if (lead && v == 0) {
            res += dfs(pos + 1, 11, limit && (v == num[pos]), true);
        } else {
            res += dfs(pos + 1, v, limit && (v == num[pos]), false);
        }
    }
    return dp[pos][last][limit][lead] = res;
}

int calc(int x) {
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    n = num.size();
    reverse(num.begin(), num.end());
    int res = dfs(0, 11, true, true);
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int l = calc(a - 1), r = calc(b);
    cout << r - l << endl;
}

int main() {
    solve();
    return 0;
}

