/*
ID: frankzh1
TASK: concom
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 105;
int mat[MAXN][MAXN];
int control[MAXN];
bool vst[MAXN];
int vertex;

void dfs(int u) {
    vst[u] = true; // controled
    for (int v = 1; v <= vertex; v++) {
        control[v] += mat[u][v];
        if (control[v] > 50 && !vst[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vertex = 0;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vertex = max(vertex, u);
        vertex = max(vertex, v);
        mat[u][v] += w;
    }
    for (int i = 1; i <= vertex; i++) {
        memset(control, 0, sizeof(control));
        memset(vst, 0, sizeof(vst));
        dfs(i);
        for (int j = 1; j <= vertex; j++) {
            if (control[j] > 50 && i != j) {
                cout << i << " " << j << endl;
            }
        }
    }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    solve();
    return 0;
}

