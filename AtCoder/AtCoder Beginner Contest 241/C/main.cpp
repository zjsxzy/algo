#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1005;
int n;
string grid[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int h = 0;
            bool out = false;
            for (int k = 0; k < 6; k++) {
                if (j + k >= n) {
                    out = true;
                    break;
                }
                if (grid[i][j + k] == '.') h++;
            }
            if (!out && h <= 2) {
                cout << "Yes" << endl;
                return;
            }

            int v = 0;
            out = false;
            for (int k = 0; k < 6; k++) {
                if (i + k >= n) {
                    out = true;
                    break;
                }
                if (grid[i + k][j] == '.') v++;
            }
            if (!out && v <= 2) {
                cout << "Yes" << endl;
                return;
            }

            int d = 0;
            out = false;
            for (int k = 0; k < 6; k++) {
                if (i + k >= n || j + k >= n) {
                    out = true;
                    break;
                }
                if (grid[i + k][j + k] == '.') d++;
            }
            if (!out && d <= 2) {
                cout << "Yes" << endl;
                return;
            }

            int d2 = 0;
            out = false;
            for (int k = 0; k < 6; k++) {
                if (i - k < 0 || j + k >= n) {
                    out = true;
                    break;
                }
                if (grid[i - k][j + k] == '.') d2++;
            }
            if (!out && d2 <= 2) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

