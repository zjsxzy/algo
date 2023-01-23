#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    union_find dsu(3 * n);
    int res = 0;
    for (int i = 0; i < k; i++) {
        int d, x, y;
        cin >> d >> x >> y;
        x--; y--;
        if (x < 0 || x >= n || y < 0 || y >= n) {
            res++;
            continue;
        }
        if (d == 1) {
            if (dsu.same(x, y + n) || dsu.same(x, y + 2 * n)) {
                res++;
            } else {
                dsu.unite(x, y);
                dsu.unite(x + n, y + n);
                dsu.unite(x + 2 * n, y + 2 * n);
            }
        } else {
            if (dsu.same(x, y) || dsu.same(x, y + 2 * n)) {
                res++;
            } else {
                dsu.unite(x, y + n);
                dsu.unite(x + n, y + 2 * n);
                dsu.unite(x + 2 * n, y);
            }
        }
    }
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