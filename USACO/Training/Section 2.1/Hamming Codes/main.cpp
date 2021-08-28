/*
ID: frankzh1
TASK: hamming
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> res;
    res.emplace_back(0);
    for (int i = 1; i < (1 << 8); i++) {
        if (res.size() == n) break;
        bool flag = true;
        for (auto &x: res) {
            int diff = __builtin_popcount(x ^ i);
            if (diff < d) {
                flag = false;
                break;
            }
        }
        if (flag) res.emplace_back(i);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i > 0 && (i + 1) % 10 == 0) cout << endl;
        else if (i == res.size() - 1) cout << endl;
        else cout << " ";
    }
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    solve();
    return 0;
}

