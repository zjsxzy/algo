#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dist(int i, int j, int x, int y) {
    return abs(i - x) + abs(j - y);
}

void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            for (int a = 0; a < H; a++) {
                for (int b = 0; b < W; b++) {
                    if (S[a][b] == '#' || (i == a && j == b)) continue; 
                    int cnt = 0;
                    for (int x = 0; x < H; x++) {
                        for (int y = 0; y < W; y++) {
                            if (S[x][y] == '#') continue;
                            if (dist(x, y, i, j) <= D || dist(x, y, a, b) <= D) {
                                cnt++;
                            }
                        }
                    }
                    // cout << i << ' ' << j << ' ' << a << ' ' << b << endl;
                    res = max(res, cnt);
                    // cout << cnt << endl;
                }
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