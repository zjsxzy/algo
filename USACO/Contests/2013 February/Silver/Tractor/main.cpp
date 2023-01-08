#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }
    auto check = [&](int x) {
        union_find dsu(n * n);
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && abs(h[i][j] - h[ni][nj]) <= x) {
                        dsu.unite(i * n + j, ni * n + nj);
                    }
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n * n; i++) {
            if (dsu.root(i) == i) {
                mx = max(mx, dsu.siz[i]);
            }
        }
        return mx * 2 >= n * n;
    };
    int lo = 0, hi = 1e7, res;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}