#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;
const int maxn = 5005;
int a[maxn], s[maxn];
int dp[maxn][maxn];

int calc(int l, int r) {
    //cout << l << " " << r << endl;
    //if (l > r) return inf;
    if (l == r) {
        if (a[l] == 0) return dp[l][r] = 0;
        else return dp[l][r] = inf;
    }
    int sum = s[r] - s[l - 1];
    if (dp[l][r] != inf) return dp[l][r];
    if (sum > r - l + 1 - sum) return dp[l][r] = inf;
    //if (sum == 1) return dp[l][r] = 1;
    //if (sum == 0) return dp[l][r] = 0;
    int res = inf;
    for (int k = l; k < r; k++) {
        int left = calc(l, k);
        if (left == inf) continue;
        int right = calc(k + 1, r);
        if (left + right < res) res = left + right;
    }
    if (res == inf) return dp[l][r] = sum * sum;
    return dp[l][r] = res;
}

void solve() {
    int n;
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = inf;
        }
    }
    int res = calc(1, n);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

