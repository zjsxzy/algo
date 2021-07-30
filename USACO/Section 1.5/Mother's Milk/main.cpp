/*
ID: frankzh1
TASK: milk3
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 22;
int A, B, C;
bool vst[MAXN][MAXN][MAXN];
bool res[MAXN];

void dfs(int a, int b, int c) {
    if (vst[a][b][c]) return;
    vst[a][b][c] = 1;

    if (a == 0 && !res[c]) res[c] = true;

    if (c >= (A - a)) dfs(A, b, c - (A - a));
    else dfs(a + c, b, 0);

    if (c >= (B - b)) dfs(a, B, c - (B - b));
    else dfs(a, b + c, 0);

    if (b >= (A - a)) dfs(A, b - (A - a), c);
    else dfs(b + a, 0, c);

    if (b >= (C - c)) dfs(a, b - (C - c), C);
    else dfs(a, 0, b + c);

    if (a >= (C - c)) dfs(a - (C - c), b, C);
    else dfs(0, b, a + c);

    if (a >= (B - b)) dfs(a - (B - b), B, c);
    else dfs(0, a + b, c);
}

void solve() {
    cin >> A >> B >> C;

    dfs(0, 0, C);

    for (int i = 0; i < MAXN; i++) {
        if (res[i]) cout << i << " ";
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    solve();
    return 0;
}

