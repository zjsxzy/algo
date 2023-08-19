#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {

    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    for (auto& s: c) cin >> s;
    set<int> row, col;
    for (int i = 0; i < n; i++) row.insert(i);
    for (int j = 0; j < m; j++) col.insert(j);
    vector crow(n, vector(26, 0)), ccol(m, vector(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            crow[i][c[i][j] - 'a']++;
            ccol[j][c[i][j] - 'a']++;
        }
    }
    while (true) {
        vector<pair<int, int>> delrow, delcol;
        if (col.size() > 1) {
            for (auto i: row) {
                for (int k = 0; k < 26; k++) {
                    if (crow[i][k] == col.size()) {
                        delrow.push_back({i, k});
                    }
                }
            }
        }
        if (row.size() > 1) {
            for (auto j: col) {
                for (int k = 0; k < 26; k++) {
                    if (ccol[j][k] == row.size()) {
                        delcol.push_back({j, k});
                    }
                }
            }
        }
        if (delrow.size() == 0 && delcol.size() == 0) break;
        for (auto [i, k]: delrow) {
            row.erase(i);
            for (auto j: col) {
                ccol[j][k]--;
            }
        }
        for (auto [j, k]: delcol) {
            col.erase(j);
            for (auto i: row) {
                crow[i][k]--;
            }
        }
        if (row.size() == 0 || col.size() == 0) break;
    }
    int res = (int)row.size() * col.size();
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