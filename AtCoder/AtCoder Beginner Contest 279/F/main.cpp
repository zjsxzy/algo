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
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    union_find dsu(n + q);
    int k = n;
    vector<int> ball(n), box(n + q);
    iota(ball.begin(), ball.end(), 0);
    iota(box.begin(), box.end(), 0);
    for (int i = 0; i < q; i++) {
        int op, x, y;
        cin >> op;
        if (op == 3) {
            cin >> x;
            x--;
            cout << box[dsu.root(x)] + 1 << endl;
        } else if (op == 2) {
            cin >> x;
            x--;
            box[k] = x;
            if (ball[x] == -1) {
                ball[x] = k;
            } else {
                dsu.unite(k, ball[x]);
            }
            k++;
        } else if (op == 1) {
            cin >> x >> y;
            x--; y--;
            if (ball[y] == -1) continue;
            if (ball[x] == -1) {
                ball[x] = ball[y];
                box[ball[x]] = x;
            } else {
                dsu.unite(ball[y], ball[x]);
            }
            ball[y] = -1;
        }
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


