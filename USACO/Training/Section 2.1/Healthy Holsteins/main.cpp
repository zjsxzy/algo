/*
ID: frankzh1
TASK: holstein
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int v;
    cin >> v;
    vector<int> vitamin(v);
    for (auto &x: vitamin) {
        cin >> x;
    }
    int g;
    cin >> g;
    vector<vector<int>> feed(g, vector<int>(v));
    for (auto &vec: feed) {
        for (auto &x: vec) {
            cin >> x;
        }
    }
    int res = v, state = (1 << g) - 1;
    for (int s = 0; s < (1 << g); s++) {
        vector<int> sum(v);
        for (int i = 0; i < g; i++) {
            if (s & (1 << i)) {
                for (int j = 0; j < v; j++) {
                    sum[j] += feed[i][j];
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < v; j++) {
            if (sum[j] < vitamin[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int bits = __builtin_popcount(s);
            if (bits < res || (bits == res && s < state)) {
                res = bits;
                state = s;
            }
        }
    }
    cout << res;
    for (int i = 0; i < g; i++) {
        if (state & (1 << i)) {
            cout << " " << i + 1;
        }
    }
    cout << endl;
}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    solve();
    return 0;
}

