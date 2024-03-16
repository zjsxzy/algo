#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> C(n);
    for (auto& s: C) cin >> s;
    vector<vector<int>> f(n, vector<int>(m));
    f[0][0] = 1;
    string res{C[0][0]};
    for (int l = 2; l < n + m; l++) {
        char c = '-';
        for (int i = 0; i < n; i++) {
            int j = l - i - 1;
            if (j < 0 || j >= m) continue;
            if (i > 0 && f[i - 1][j]) {
                if (c == '-' || C[i][j] < c) c = C[i][j];
            }
            if (j > 0 && f[i][j - 1]) {
                if (c == '-' || C[i][j] < c) c = C[i][j];
            }
        }
        res += c;
        for (int i = 0; i < n; i++) {
            int j = l - i - 1;
            if (j < 0 || j >= m) continue;
            if (i > 0 && f[i - 1][j] && C[i][j] == c) f[i][j] = 1;
            if (j > 0 && f[i][j - 1] && C[i][j] == c) f[i][j] = 1;
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