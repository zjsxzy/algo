/*
ID: frankzh1
TASK: latin
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n;
int row[7][8], col[7][8];
int m[7], visited[7];
LL gCount[8];
int fact[7] = {0, 1, 2, 6, 24, 120, 720};

int find() {
    int ans = 2;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cnt = 0, p = i;
            do {
                visited[p] = 1;
                p = m[p];
                cnt++;
            } while (!visited[p]);
            ans = max(ans, cnt);
        }
    }
    return ans;
}

LL dfs(int x, int y, int group) {
    if (x == n - 1) {
        gCount[group]++;
        return 1;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (!row[x][i] && !col[y][i]) {
            if (x == 1) {
                m[y] = i;
                if (y == n - 1) {
                    group = find();
                    if (gCount[group] > 0) return gCount[group];
                }
            }
            row[x][i] = 1;
            col[y][i] = 1;
            if (y < n - 1) ans += dfs(x, y + 1, group);
            else ans += dfs(x + 1, 1, group);
            row[x][i] = 0;
            col[y][i] = 0;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        row[i][i] = 1;
        col[i][i] = 1;
    }
    m[0] = 1;
    LL res = dfs(1, 1, 0) * fact[n - 1];
    cout << res << endl;
}

int main() {
    freopen("latin.in", "r", stdin);
    freopen("latin.out", "w", stdout);
    solve();
    return 0;
}

