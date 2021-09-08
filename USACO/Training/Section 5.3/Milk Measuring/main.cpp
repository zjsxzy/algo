/*
ID: frankzh1
TASK: milk4
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
const int maxm = 20005;
int p, q, d;
int a[maxn], use[maxn];
bool dp[maxm];

bool check() {
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j + use[i] <= q; j++) {
            dp[j + use[i]] |= dp[j];
        }
    }
    return dp[q];
}

bool dfs(int dep, int now) {
    if (dep == d) return check();
    for (int i = now; i < p; i++) {
        use[dep] = a[i];
        if (dfs(dep + 1, now + 1)) return true;
    }
    return false;
}

void solve() {
    cin >> q >> p;
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }
    sort(a, a + p);
    for (d = 1; d <= p; d++) {
        if (dfs(0, 0)) break;
    }
    cout << d;
    for (int i = 0; i < d; i++) {
        cout << " " << use[i];
    }
    cout << endl;
}

int main() {
    freopen("milk4.in", "r", stdin);
    freopen("milk4.out", "w", stdout);
    solve();
    return 0;
}

