#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector vst(n, vector(m, 0));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int cnt, li, ri, lj, rj;
    function<void(int, int)> dfs = [&](int i, int j) {
        li = min(li, i); ri = max(ri, i);
        lj = min(lj, j); rj = max(rj, j);
        vst[i][j] = true;
        cnt++;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] == '.' && !vst[ni][nj]) {
                dfs(ni, nj);
            }
        }
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !vst[i][j]) {
                cnt = 0;
                li = i; ri = i;
                lj = j; rj = j;
                dfs(i, j);
                res += (ri - li + 1) * (rj - lj + 1) == cnt;
            }
        }
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}