#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 3000 + 5;
string grid[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int res = 0, all = n * m;
    while (all) {
        int mx_row = 0, row = -1;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int r = 0, b = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'R') r++;
                else if (grid[i][j] == 'B') b++;
                if (r && b) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (r + b > mx_row) {
                    row = i;
                    mx_row = r + b;
                }
            }
        }

        int mx_col = 0, col = -1;
        for (int j = 0; j < m; j++) {
            bool flag = true;
            int r = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'R') r++;
                else if (grid[i][j] == 'B') b++;
                if (r && b) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (r + b > mx_col) {
                    col = j;
                    mx_col = r + b;
                }
            }
        }
        if (mx_row == 0 && mx_col == 0) {
            cout << -1 << endl;
            return;
        }
        res++;
        if (mx_row > mx_col) {
            cout << row << endl;
            for (int j = 0; j < m; j++) {
                if (grid[row][j] != '*') {
                    grid[row][j] = '*';
                }
            }
            all += mx_row;
        } else {
            cout << col << endl;
            for (int i = 0; i < n; i++) {
                if (grid[i][col] != '*') {
                    grid[i][col] = '*';
                }
            }
            all += mx_col;
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

