#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    map<pair<int, int>, int> pos;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        pos[{x, y}]++;
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'L') {
            x--;
        } else if (c == 'R') {
            x++;
        } else if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        }
        H--;
        if (H < 0) {
            cout << "No" << endl;
            return;
        }
        if (H < K && pos.find({x, y}) != pos.end() && pos[{x, y}] > 0) {
            H = K;
            pos[{x, y}]--;
        }
    }
    cout << "Yes" << endl;
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