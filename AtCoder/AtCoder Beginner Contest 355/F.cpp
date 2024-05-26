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
    bool unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return false;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        return true;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<union_find> dsu(11, union_find(N));
    vector<int> siz(11, N);
    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        for (int j = c; j <= 10; j++) {
            siz[j] -= dsu[j].unite(a, b);
        }
    }
    while (Q--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        for (int j = w; j <= 10; j++) {
            siz[j] -= dsu[j].unite(u, v);
        }
        int res = 0, last = N;
        for (int j = 1; j <= 10; j++) {
            res += j * (last - siz[j]);
            last = siz[j];
        }
        cout << res << endl;
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