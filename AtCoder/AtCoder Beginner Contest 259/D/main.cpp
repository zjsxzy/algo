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

LL dist2(LL x1, LL y1, LL x2, LL y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    int n;
    cin >> n;
    union_find uf(n);
    vector<LL> x(n), y(n), r(n);
    LL sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int s, t;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        if (dist2(x[i], y[i], sx, sy) == r[i] * r[i]) s = i;
        if (dist2(x[i], y[i], tx, ty) == r[i] * r[i]) t = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL d = dist2(x[i], y[i], x[j], y[j]);
            LL rx = max(r[i], r[j]), rm = min(r[i], r[j]);
            if (d == (r[i] + r[j]) * (r[i] + r[j])) {
                uf.unite(i, j);
            } else if (d < (r[i] + r[j]) * (r[i] + r[j])) {
                if (d >= (rx - rm) * (rx - rm)) {
                    uf.unite(i, j);
                }
            }
        }
    }
    if (uf.same(s, t)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

