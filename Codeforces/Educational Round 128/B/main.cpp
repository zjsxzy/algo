#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    queue<vector<string>> q;
    q.push(s);
    map<vector<string>, int> step;
    step[s] = 0;
    while (!q.empty()) {
        vector<string> t = q.front(); q.pop();
        if (t[0][0] == 'R') {
            cout << "YES" << endl;
            return;
        }
        if (step[t] > n + m) break;
        for (int d = 0; d < 4; d++) {
            bool outside = false;
            vector<string> nt(n, string(m, 'E'));
            for (int i = 0; i < n && !outside; i++) {
                for (int j = 0; j < m && !outside; j++) {
                    if (t[i][j] == 'R') {
                        int x = i + dx[d], y = j + dy[d];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            outside = true;
                            break;
                        }
                        nt[x][y] = 'R';
                    }
                }
            }
            if (!outside && step.find(nt) == step.end()) {
                q.push(nt);
                step[nt] = step[t] + 1;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

