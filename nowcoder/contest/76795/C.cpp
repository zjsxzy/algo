#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    for (auto& s: c) cin >> s;
    int red = 0, cnt = 0;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> color(n, vector<int>(m));
    function<void(int, int)> dfs = [&](int i, int j) {
        // cout << i << ' ' << j << endl;
        cnt++;
        color[i][j] = red;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && c[ni][nj] == '#' && !color[ni][nj]) {
                dfs(ni, nj);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '#' && !color[i][j]) {
                red++;
                dfs(i, j);
            }
        }
    }
    if (cnt == 0) {
        cout << "Blue" << endl;
        return;
    }
    vector<int> blue(red + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                set<int> st;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && color[ni][nj]) {
                        st.insert(color[ni][nj]);
                    }
                }
                for (auto x: st) blue[x]++;
            }
        }
    }
    for (int i = 1; i <= red; i++) {
        // cout << i << ' ' << blue[i] << endl;
        if (blue[i] == n * m - cnt) {
            cout << "Red" << endl;
            return;
        }
    }
    cout << "Draw" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}