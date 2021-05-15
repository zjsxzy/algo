#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 2005;
int a[MAXN][MAXN], dp[MAXN][MAXN];

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> mat(h);
    for (auto &x : mat) {
        cin >> x;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            a[i][j] = mat[i - 1][j - 1] == '+' ? 1 : -1;
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = h; i >= 1; i--) {
        for (int j = w; j >= 1; j--) {
            if (i == h && j == w) continue;
            if ((i + j) & 1) {
                if (i == h) {
                    dp[i][j] = dp[i][j + 1] - a[i][j + 1];
                } else if (j == w) {
                    dp[i][j] = dp[i + 1][j] - a[i + 1][j];
                } else {
                    dp[i][j] = min(dp[i][j + 1] - a[i][j + 1], dp[i + 1][j] - a[i + 1][j]);
                }
            } else {
                if (i == h) {
                    dp[i][j] = dp[i][j + 1] + a[i][j + 1];
                } else if (j == w) {
                    dp[i][j] = dp[i + 1][j] + a[i + 1][j];
                } else {
                    dp[i][j] = max(dp[i][j + 1] + a[i][j + 1], dp[i + 1][j] + a[i + 1][j]);
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    if (dp[1][1] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[1][1] == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

