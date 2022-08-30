#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '^') {
                q.push({i, j});
            }
        }
    }
    if (q.empty()) {
        cout << "Possible" << endl;
        for (int i = 0; i < r; i++) cout << s[i] << endl;
        return;
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    auto check = [&](int x, int y) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (s[nx][ny] == '.' || s[nx][ny] == '^') cnt++;
            }
        }
        return cnt >= 2;
    };
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int i = t.first, j = t.second;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && s[ni][nj] == '.') {
                if (check(ni, nj)) {
                    s[ni][nj] = '^';
                    q.push({ni, nj});
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] != '^') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && s[ni][nj] == '^') cnt++;
            }
            if (cnt < 2) {
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    cout << "Possible" << endl;
    for (int i = 0; i < r; i++) cout << s[i] << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

