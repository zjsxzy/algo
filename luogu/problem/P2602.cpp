#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 15;
vector<int> num;
int n, digit;
LL dp[maxn][maxn][2][2];

LL dfs(int pos, int cnt, bool limit, bool lead) {
    LL res = 0;
    if (pos == n) return cnt;
    if (dp[pos][cnt][limit][lead] != -1) return dp[pos][cnt][limit][lead];
    for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
        if (lead && v == 0) {
            res += dfs(pos + 1, cnt, limit && v == num[pos], true);
        } else {
            res += dfs(pos + 1, cnt + (v == digit), limit && v == num[pos], false);
        }
    }
    return dp[pos][cnt][limit][lead] = res;
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
    LL res = dfs(0, 0, true, true);
    return res;
}

void solve() {
    LL a, b;
    cin >> a >> b;
    for (int i = 0; i < 10; i++) {
        digit = i;
        LL r = calc(b), l = calc(a - 1);
        cout << r - l << " ";
    }
}

int main() {
    solve();
    return 0;
}

