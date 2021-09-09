/*
ID: frankzh1
TASK: twofive
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int vis[30];
int f[7][7][7][7][7];

bool check(int i, int num) {
    return vis[i] == 0 || vis[i] == num;
}

int dfs(int a, int b, int c, int d, int e, int x) {
    if (x > 25) return 1;
    if (f[a][b][c][d][e]) return f[a][b][c][d][e];
    int res = 0;
    if (a <= 5 && check(a, x)) res += dfs(a + 1, b, c, d, e, x + 1);
    if (b < a && check(b + 5, x)) res += dfs(a, b + 1, c, d, e, x + 1);
    if (c < b && check(c + 10, x)) res += dfs(a, b, c + 1, d, e, x + 1);
    if (d < c && check(d + 15, x)) res += dfs(a, b, c, d + 1, e, x + 1);
    if (e < d && check(e + 20, x)) res += dfs(a, b, c, d, e + 1, x + 1);
    return f[a][b][c][d][e] = res;
}

void solve() {
    char opt;
    cin >> opt;
    if (opt == 'W') {
        int res = 0;
        string s;
        cin >> s;
        for (int i = 1; i <= 25; i++) {
            for (vis[i] = 1; vis[i] < s[i - 1] - 'A' + 1; vis[i]++) {
                memset(f, 0, sizeof(f));
                res += dfs(1, 1, 1, 1, 1, 1);
            }
        }
        cout << res + 1 << endl;
    } else {
        int n;
        cin >> n;
        for (int i = 1; i <= 25; i++) {
            for (vis[i] = 1; ; vis[i]++) {
                memset(f, 0, sizeof(f));
                int tmp = dfs(1, 1, 1, 1, 1, 1);
                if (tmp >= n) break;
                n -= tmp;
            }
        }
        for (int i = 1; i <= 25; i++) {
            cout << (char)(vis[i] - 1 + 'A');
        }
        cout << endl;
    }
}

int main() {
    freopen("twofive.in", "r", stdin);
    freopen("twofive.out", "w", stdout);
    solve();
    return 0;
}

