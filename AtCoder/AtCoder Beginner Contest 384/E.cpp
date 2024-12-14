#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int H, W, X;
    cin >> H >> W >> X;
    int P, Q;
    cin >> P >> Q;
    P--; Q--;
    vector S(H, vector<LL>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }
    vector dx = {0, 0, -1, 1};
    vector dy = {-1, 1, 0, 0};
    set<pair<LL, pair<int, int>>> pq;
    unsigned long long ans = S[P][Q];
    S[P][Q] = 0;
    for (int k = 0; k < 4; k++) {
        int x = P + dx[k], y = Q + dy[k];
        if (x >= 0 && x < H && y >= 0 && y < W) {
            pq.insert({S[x][y], {x, y}});
        }
    }
    while (!pq.empty()) {
        auto t = pq.begin(); 
        pq.erase(t);
        LL val = t->first;
        int x = t->second.first, y = t->second.second;
        // cout << x + 1 << ' ' << y + 1 << ' ' << ans << ' ' << val << endl;
        if ((__int128)val * X >= ans) break;
        S[x][y] = 0;
        ans += val;
        // cout << ans << '\n';
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && S[nx][ny] > 0) {
                // cout << nx << ' ' << ny << ' ' << S[nx][ny] << '\n';
                pq.insert({S[nx][ny], {nx, ny}});
            }
        }
    }
    cout << ans << '\n';
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