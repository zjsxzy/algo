#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int mg;
    cin >> mg;
    vector g(n, vector<int>(n, 0));
    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = g[v][u] = 1;
    }
    int mh;
    cin >> mh;
    vector h(n, vector<int>(n, 0));
    for (int i = 0; i < mh; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        h[a][b] = h[b][a] = 1;
    }
    vector A(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> A[i][j];
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int res = 1e9;
    do {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[p[i]][p[j]] != h[i][j]) {
                    sum += A[i][j];
                }
            }
        }
        res = min(res, sum);
    } while (next_permutation(p.begin(), p.end()));
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}