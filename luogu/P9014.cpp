#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> dir(n);
    vector<vector<int>> cost(n + 1, vector<int>(n + 1)), cowcnt(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> cost[i][n];
    }
    for (int j = 0; j < n; j++) {
        cin >> cost[n][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cowcnt[i][j]++;
            if (dir[i][j] == 'R') cowcnt[i][j + 1] += cowcnt[i][j];
            else cowcnt[i + 1][j] += cowcnt[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cowcnt[n][i] * cost[n][i] + cowcnt[i][n] * cost[i][n];
    }
    cout << ans << endl;
    auto flip = [&](int x, int y, char d) {
        int cnt = cowcnt[x][y];
        int i = x, j = y;
        while (i != n && j != n) {
            if (dir[i][j] == 'R') j++;
            else i++;
            cowcnt[i][j] -= cnt;
        }
        ans -= cost[i][j] * cnt;

        dir[x][y] = d;
        i = x, j = y;
        while (i != n && j != n) {
            if (dir[i][j] == 'R') j++;
            else i++;
            cowcnt[i][j] += cnt;
        }
        ans += cost[i][j] * cnt;
    };
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (dir[x][y] == 'D') {
            flip(x, y, 'R');
        } else {
            flip(x, y, 'D');
        }
        cout << ans << endl;
    }
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