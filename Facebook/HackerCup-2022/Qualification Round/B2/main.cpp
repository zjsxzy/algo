#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    vector<vector<int>> d(r, vector<int>(c));
    vector<vector<int>> ban(r, vector<int>(c));
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    auto check = [&](int x, int y) {
        return x >= 0 && x < r && y >= 0 && y < c && s[x][y] != '#';
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] != '#') {
                for (int k = 0; k < 4; k++) {
                    d[i][j] += check(i + dx[k], j + dy[k]);
                }
            }
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] != '#' && d[i][j] < 2) q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        ban[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (check(ni, nj) && (d[ni][nj] -= 1) == 1) {
                 q.emplace(ni, nj);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '#') continue;
            if (ban[i][j]) {
                if (s[i][j] == '^') {
                    cout << "Impossible" << endl;
                    return;
                }
            } else {
                s[i][j] = '^';
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

