#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 3000 + 5;
int n, m, res;
bool row[MAXN], col[MAXN];
string grid[MAXN], curr[MAXN];

void dfs(int r, int c, int step) {
    if (r == n) return;
    if (c == m) return;
    if (step >= res) return;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (curr[i] != grid[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        res = min(res, step);
        return;
    }
    // flip row r
    for (int j = 0; j < m; j++) {
        curr[r][j] = 'R';
    }
    // flip column c
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        string str(m, '*');
        curr[i] = str;
    }
    res = INT_MAX;
    dfs(0, 0, 0);
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

