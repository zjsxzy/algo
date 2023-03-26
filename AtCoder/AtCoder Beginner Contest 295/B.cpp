#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    vector<string> ans(r);
    ans = grid;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                int power = grid[i][j] - '0';
                ans[i][j] = '.';
                for (int x = 0; x < r; x++) {
                    for (int y = 0; y < c; y++) {
                        if (grid[x][y] == '.' || grid[x][y] == '#') {
                            if (abs(i - x) + abs(j - y) <= power) ans[x][y] = '.';
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++) cout << ans[i] << endl;
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