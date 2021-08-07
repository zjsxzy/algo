/*
ID: frankzh1
TASK: lamps
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, C;
    cin >> n >> C;
    vector<int> final_state(n + 1, -1);
    int i;
    while (cin >> i) {
        if (i == -1) break;
        final_state[i] = 1;
    }
    while (cin >> i) {
        if (i == -1) break;
        final_state[i] = 0;
    }

    vector<vector<int>> res;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++)
                for (int d = 0; d < 2; d++) {
                    if (a + b + c + d > C) continue;
                    if ((a + b + c + d) % 2 != C % 2) continue;
                    vector<int> state(n + 1, 1);
                    if (a) {
                        for (int i = 1; i <= n; i++) {
                            state[i] ^= 1;
                        }
                    }
                    if (b) {
                        for (int i = 1; i <= n; i+=2) {
                            state[i] ^= 1;
                        }
                    }
                    if (c) {
                        for (int i = 2; i <= n; i+=2) {
                            state[i] ^= 1;
                        }
                    }
                    if (d) {
                        for (int i = 1; i <= n; i+=3) {
                            state[i] ^= 1;
                        }
                    }
                    bool flag = true;
                    for (int i = 1; i <= n; i++) {
                        if (final_state[i] == -1) continue;
                        if (state[i] != final_state[i]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) res.push_back(state);
                }

    if (res.size() == 0) cout << "IMPOSSIBLE" << endl;
    else {
        sort(res.begin(), res.end());
        for (auto &v: res) {
            for (int i = 1; i <= n; i++) {
                cout << v[i];
            }
            cout << endl;
        }
    }
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    solve();
    return 0;
}

