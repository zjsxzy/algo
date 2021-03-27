#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<string> mat(n);
    for (auto &s : mat) {
        cin >> s;
    }
    int res = 1;
    for (int j = y + 1; j < m; j++) {
        if (mat[x][j] == '.') res++;
        else break;
    }
    for (int j = y - 1; j >= 0; j--) {
        if (mat[x][j] == '.') res++;
        else break;
    }
    for (int i = x + 1; i < n; i++) {
        if (mat[i][y] == '.') res++;
        else break;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (mat[i][y] == '.') res++;
        else break;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

