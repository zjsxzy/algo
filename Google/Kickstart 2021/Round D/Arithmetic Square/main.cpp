#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    vector<vector<int>> a(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        cin >> a[0][i];
    }
    cin >> a[1][0] >> a[1][2];
    for (int i = 0; i < 3; i++) {
        cin >> a[2][i];
    }
    map<int, int> cnt;

    if ((a[0][0] + a[2][2]) % 2 == 0) {
        cnt[(a[0][0] + a[2][2]) / 2]++;
    }
    if ((a[2][0] + a[0][2]) % 2 == 0) {
        cnt[(a[2][0] + a[0][2]) / 2]++;
    }
    if ((a[1][0] + a[1][2]) % 2 == 0) {
        cnt[(a[1][0] + a[1][2]) / 2]++;
    }
    if ((a[0][1] + a[2][1]) % 2 == 0) {
        cnt[(a[0][1] + a[2][1]) / 2]++;
    }
    int mx = 0;
    for (auto &[k, v]: cnt) {
        if (v > mx) mx = v;
    }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (i == 1) continue;
        if (a[i][0] + a[i][2] == a[i][1] * 2) res++;
    }
    for (int j = 0; j < 3; j++) {
        if (j == 1) continue;
        if (a[0][j] + a[2][j] == a[1][j] * 2) res++;
    }
    cout << res + mx << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}

