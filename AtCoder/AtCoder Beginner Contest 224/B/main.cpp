#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int a[55][55];
void solve() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i1 = 1; i1 <= h; i1++) {
        for (int i2 = i1 + 1; i2 <= h; i2++) {
            for (int j1 = 1; j1 <= w; j1++) {
                for (int j2 = j1 + 1; j2 <= w; j2++) {
                    if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) {
                        // cout << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

