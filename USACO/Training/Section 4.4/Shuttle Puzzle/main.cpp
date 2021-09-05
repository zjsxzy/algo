/*
ID: frankzh1
TASK: shuttle
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 300005;
int n;
char b[32];
int q[maxn];
int Ans, ans[maxn];

bool valid() {
    if (b[n + 1] != ' ') return false;
    for (int i = 1; i <= n; i++) if (b[i] == 'W') return false;
    return true;
}

void dfs(int x, int step) {
    if (step > Ans) return;
    if (valid()) {
        if (step < Ans) {
            Ans = step;
            for (int i = 1; i <= step; i++) {
                ans[i] = q[i];
            }
        } else if (step == Ans) {
            for (int i = 1; i <= step; i++) {
                if (q[i] > ans[i]) {
                    return;
                }
            }
            for (int i = 1; i <= step; i++) {
                ans[i] = q[i];
            }
        }
    }
    if (b[x - 1] == 'W') {
        b[x] = 'W';
        b[x - 1] = ' ';
        q[step + 1] = x - 1;
        dfs(x - 1, step + 1);
        b[x - 1] = 'W';
        b[x] = ' ';
    }
    if (b[x + 1] == 'B') {
        b[x] = 'B';
        b[x + 1] = ' ';
        q[step + 1] = x + 1;
        dfs(x + 1, step + 1);
        b[x + 1] = 'B';
        b[x] = ' ';
    }
    if (x > 1 && b[x - 1] == 'B' && b[x - 2] == 'W') {
        b[x] = 'W';
        b[x - 2] = ' ';
        q[step + 1] = x - 2;
        dfs(x - 2, step + 1);
        b[x - 2] = 'W';
        b[x] = ' ';
    }
    if (x < 2 * n + 1 && b[x + 1] == 'W' && b[x + 2] == 'B') {
        b[x] = 'B';
        b[x + 2] = ' ';
        q[step + 1] = x + 2;
        dfs(x + 2, step + 1);
        b[x + 2] = 'B';
        b[x] = ' ';
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        b[i] = 'W';
    }
    b[n + 1] = ' ';
    for (int i = n + 2; i <= 2 * n + 1; i++) {
        b[i] = 'B';
    }
    Ans = maxn;
    dfs(n + 1, 0);
    for (int i = 1; i <= Ans; i++) {
        cout << ans[i];
        if (i % 20 == 0 || i == Ans) cout << endl;
        else cout << " ";
    }
}

int main() {
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    solve();
    return 0;
}

