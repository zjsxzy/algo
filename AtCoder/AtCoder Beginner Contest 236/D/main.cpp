#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 20;
int n, res;
int A[maxn][maxn];

void dfs(int state, int sum) {
    if (state == (1 << (2 * n)) - 1) {
        res = max(res, sum);
        return;
    }
    int i;
    for (i = 0; i < 2 * n; i++) {
        if (!(state & (1 << i))) {
            break;
        }
    }
    for (int j = i + 1; j < 2 * n; j++) {
        if (!(state & (1 << j))) {
            dfs(state | (1 << i) | (1 << j), sum ^ A[i + 1][j + 1]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = i + 1; j <= 2 * n; j++) {
            cin >> A[i][j];
        }
    }
    res = 0;
    dfs(0, 0);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

