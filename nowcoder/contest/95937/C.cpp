#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    auto calc = [&](vector<string> m) {
        int sz = m[0].size();
        vector<vector<int>> vst(2, vector<int>(sz));
        int cnt = 0;
        // cout << m[0] << endl;
        // cout << m[1] << endl;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < sz; j++) {
                if (m[i][j] == '.' && !vst[i][j]) {
                    cnt++;
                    vst[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto u = q.front(); q.pop();
                        for (int k = 0; k < 4; k++) {
                            int ni = u.first + dx[k], nj = u.second + dy[k];
                            if (ni >= 0 && ni < 2 && nj >= 0 && nj < sz && m[ni][nj] == '.' && !vst[ni][nj]) {
                                vst[ni][nj] = true;
                                q.push({ni, nj});
                            }
                        }
                    }
               }
            }
        }
        // cout << cnt << endl;
        return cnt;
    };
    int res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.') {
                // cout << i << ' ' << j << endl;
                vector<string> a(2);
                if (j == 0) {
                    a[0] = s[0].substr(j, 2);
                    a[1] = s[1].substr(j, 2);
                } else if (j == n - 1) {
                    a[0] = s[0].substr(j - 1, 2);
                    a[1] = s[1].substr(j - 1, 2);
                } else {
                    a[0] = s[0].substr(j - 1, 3);
                    a[1] = s[1].substr(j - 1, 3);
                }
                int cnt = calc(a);
                if (j == 0) a[i][0] = 'x';
                else a[i][1] = 'x';
                int t = calc(a);
                if (cnt != t) res++;
                // cout << i << ' ' << j << ' ' << cnt << ' ' << t << ' ' << res << endl;
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