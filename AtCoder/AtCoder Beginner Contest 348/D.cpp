#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    pair<int, int> start, end;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') start = {i, j};
            if (A[i][j] == 'T') end = {i, j};
        }
    }
    int N;
    cin >> N;
    vector<vector<int>> energy(H, vector<int>(W));
    for (int i = 0; i < N; i++) {
        int r, c, e;
        cin >> r >> c >> e;
        r--; c--;
        energy[r][c] = e;
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<pair<int, int>, int>> q;
    dist[start.first][start.second] = 0;
    q.push({{start.first, start.second}, 0});
    while (!q.empty()) {
        auto [p, e] = q.front(); q.pop();
        if (p == end) {
            cout << "Yes" << endl;
            return;
        }
        int i = p.first, j = p.second;
        if (energy[i][j] > e) {
            e = energy[i][j];
            energy[i][j] = 0;
        }
        // cout << i << ' ' << j << ' ' << e << endl;
        if (e == 0) continue;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && A[ni][nj] != '#') {
                if (dist[ni][nj] == -1 || e - 1 > dist[ni][nj]) {
                    dist[ni][nj] = e - 1;
                    q.push({{ni, nj}, e - 1});
                }
            }
        }
    }
    cout << "No" << endl;
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