/*
ID: frankzh1
TASK: nuggets
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 256 * 256;
int dp[MAXN + 5];
int a[MAXN];
int n;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    if (g != 1) {
        cout << 0 << endl;
        return;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= MAXN; j++) {
            if (dp[j - a[i]]) dp[j] = 1;
        }
    }
    for (int i = MAXN; i >= 0; i--) {
        if (!dp[i]) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    solve();
    return 0;
}

