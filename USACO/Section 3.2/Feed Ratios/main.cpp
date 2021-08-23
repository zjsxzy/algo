/*
ID: frankzh1
TASK: ratios
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n = 3;
    vector<int> target(n);
    for (auto &x: target) {
        cin >> x;
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int tot = 1; tot <= 300; tot++) {
        for (int i = 0; i <= min(100, tot); i++) {
            for (int j = 0; j <= min(100, tot - i); j++) {
                int k = tot - i - j;
                if (k > 100) continue;
                vector<int> sum(n);
                for (int d = 0; d < n; d++) {
                    sum[d] = i * a[0][d] + j * a[1][d] + k * a[2][d];
                }
                if (sum[0] >= target[0] && sum[1] >= target[1] && sum[2] >= target[2]) {
                    if (sum[0] * target[1] == sum[1] * target[0] && sum[1] * target[2] == sum[2] * target[1]) {
                        cout << i << " " << j << " " << k << " " << sum[0] / target[0] << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NONE" << endl;
}

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    solve();
    return 0;
}

