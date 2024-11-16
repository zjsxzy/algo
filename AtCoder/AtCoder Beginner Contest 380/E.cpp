#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz, left, right;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        left.resize(N);
        right.resize(N);
        for(int i=0; i<N; i++) {
            par[i] = i, left[i] = i, right[i] = i;
        }
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
        left[Y] = min(left[Y], left[X]);
        right[Y] = max(right[Y], right[X]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n, 1), color(n);
    iota(color.begin(), color.end(), 0);
    union_find dsu(n);
    for (int i = 0; i < q; i++) {
        int type, x, c;
        cin >> type >> x;
        x--;
        if (type == 1) {
            cin >> c;
            c--;
            int p = dsu.root(x);
            int old = color[p];
            cnt[old] -= dsu.siz[p];
            color[p] = c;
            cnt[c] += dsu.siz[p];
            int l = dsu.left[p], r = dsu.right[p];
            if (l - 1 >= 0 && color[dsu.root(l - 1)] == c) {
                dsu.unite(l - 1, p);
            }
            if (r + 1 < n && color[dsu.root(r + 1)] == c) {
                dsu.unite(p, r + 1);
            }
        } else {
            cout << cnt[x] << endl;
        }
    }
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