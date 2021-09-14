/*
ID: frankzh1
TASK: wissqu
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

char mat[8][8], path[16][10];
bool v[4][4], flag;
int ans, num[5] = {3, 3, 3, 4, 3};

bool judge(int x0, int y0, int x1, int y1, int k) {
    for (int i = x0; i <= x1; ++i)
        for (int j = y0; j <= y1; ++j)
            if (i >= 0 && i < 4 && j >= 0 && j < 4 && mat[i][j] == k + 'A') return false;
    return true;
}

void dfs(int dep) {
    if (dep == 16) {
        if (flag) {
            for (int i = 0; i < 16; ++i)
                printf("%s\n", path[i]);
            flag = false;
        }
        ans++;
        return;
    }
    for (int u = 0; u < 5; ++u)
        if (num[u]) {
            num[u]--;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (v[i][j] && judge(i - 1, j - 1, i + 1, j + 1, u)) {
                        v[i][j] = false;
                        if (flag) {
                            path[dep][0] = u + 'A';
                            path[dep][1] = ' ';
                            path[dep][2] = i + '0' + 1;
                            path[dep][3] = ' ';
                            path[dep][4] = j + '0' + 1;
                        }
                        char tmp = mat[i][j];
                        mat[i][j] = u + 'A';
                        dfs(dep + 1);
                        mat[i][j] = tmp;
                        v[i][j] = true;
                    }
            num[u]++;
        }
}

void solve() {
    for (int i = 0; i < 4; ++i)
        scanf("%s", mat[i]);
    memset(v, true, sizeof(v));
    memset(path, 0, sizeof(path));
    flag = true;
    dfs(0);
    printf("%d\n", ans);
}

int main() {
    freopen("wissqu.in", "r", stdin);
    freopen("wissqu.out", "w", stdout);
    solve();
    return 0;
}

