/*
ID: frankzh1
TASK: stamps
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;
const int MAXN = 2000005;
int dp[MAXN];

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int m = 2000000;
    for (int i = 1; i <= m; i++) {
        dp[i] = inf;
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
        if (dp[i] > k) {
            cout << i - 1 << endl;
            return;
        }
    }
}

int main() {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    solve();
    return 0;
}

