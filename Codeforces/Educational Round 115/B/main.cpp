#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n;
int lesson[1005][5];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> lesson[i][j];
        }
    }

    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            if (a == b) continue;
            int x = 0, y = 0, both = 0;
            for (int i = 0; i < n; i++) {
                if (lesson[i][a] == 1) x++;
                if (lesson[i][b] == 1) y++;
                if (lesson[i][a] == 1 && lesson[i][b] == 1) both++;
            }
            if (x + y - both == n && both >= abs(x - y)) {
                // cout << a << " " << b << endl;
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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

