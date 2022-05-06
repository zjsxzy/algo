#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> col(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> col[i][j];
        }
    }
    vector<int> vst(n, 1);
    for (int b = 0; b < m; b++) {
        int x;
        cin >> x;
        int res = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (!vst[i]) continue;
            for (int j = 0; j < m; j++) {
                if (x == col[i][j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                res++;
            } else {
                vst[i] = false;
            }
        }
        cout << res << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

