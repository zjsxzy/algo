/*
ID: frankzh1
TASK: checker
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n;
int ans[32], vis_col[32], vis_diag[32], vis_idiag[32];
LL cnt;

void dfs(int row) {
    if (row == n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < n; i++) {
                if (i != 0) cout << " ";
                cout << ans[i] + 1;
            }
            cout << endl;
        }
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!vis_col[col] && !vis_diag[row + col] && !vis_idiag[col - row + n]) {
            ans[row] = col;
            vis_col[col] = 1;
            vis_diag[row + col] = 1;
            vis_idiag[col - row + n] = 1;
            dfs(row + 1);
            vis_col[col] = 0;
            vis_diag[row + col] = 0;
            vis_idiag[col - row + n] = 0;
        }
    }
}

void solve() {
    cin >> n;
    dfs(0);
    cout << cnt << endl;
}

int main() {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    solve();
    return 0;
}

