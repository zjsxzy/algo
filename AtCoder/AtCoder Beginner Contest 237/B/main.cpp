#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

