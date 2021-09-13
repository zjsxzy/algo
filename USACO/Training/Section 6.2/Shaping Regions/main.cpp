/*
ID: frankzh1
TASK: rect1
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1005;
int mat[maxn][4], color[maxn], num[maxn];
int a, b, n;

void dfs(int x1, int y1, int x2, int y2, int c, int deep) {
    while (deep <= n && (x1 >= mat[deep][2] || y1 >= mat[deep][3] || x2 <= mat[deep][0] || y2 <= mat[deep][1])) { // no overlap
        deep++;
    }
    if (deep > n) {
        num[c] += (x2 - x1) * (y2 - y1);
        return;
    }
    if (x1 < mat[deep][0]) {
        dfs(x1, y1, mat[deep][0], y2, c, deep + 1);
        x1 = mat[deep][0];
    }
    if (y1 < mat[deep][1]) {
        dfs(x1, y1, x2, mat[deep][1], c, deep + 1);
        y1 = mat[deep][1];
    }
    if (x2 > mat[deep][2]) {
        dfs(mat[deep][2], y1, x2, y2, c, deep + 1);
        x2 = mat[deep][2];
    }
    if (y2 > mat[deep][3]) {
        dfs(x1, mat[deep][3], x2, y2, c, deep + 1);
        y2 = mat[deep][3];
    }
}

void solve() {
    cin >> a >> b >> n;
    mat[0][0] = mat[0][1] = 0;
    mat[0][2] = a;
    mat[0][3] = b;
    color[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2] >> mat[i][3] >> color[i];
    }
    memset(num, 0, sizeof(num));
    for (int i = n; i >= 0; i--) {
        dfs(mat[i][0], mat[i][1], mat[i][2], mat[i][3], color[i], i + 1);
    }
    for (int i = 1; i <= 1000; i++) {
        if (num[i] > 0) {
            cout << i << " " << num[i] << endl;
        }
    }
}

int main() {
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    solve();
    return 0;
}

