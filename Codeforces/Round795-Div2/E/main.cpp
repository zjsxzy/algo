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
    int size() {
        int cnt = 0;
        for (int i = 0; i < N; i++) cnt += (par[i] == i);
        return cnt;
    }
};

struct node {
    int val, id, type;
    bool operator < (node& p) {
        if (val != p.val) return val < p.val;
        return type < p.type;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> c(n), l(n), r(n);
    vector<node> vec;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> l[i] >> r[i];
        vec.push_back({l[i], i, 0});
        vec.push_back({r[i], i, 1});
    }
    sort(vec.begin(), vec.end());
    union_find dsu(n);
    vector<set<pair<int, int>>> st(2); // {r, id}
    for (auto e: vec) {
        int color = c[e.id];
        if (e.type == 0) { // left
            st[color].insert({r[e.id], e.id});
            if (!st[color ^ 1].empty()) {
                while (st[color ^ 1].size() > 1) {
                    auto x = st[color ^ 1].begin();
                    dsu.unite(e.id, x->second);
                    st[color ^ 1].erase(x);
                }
                dsu.unite(e.id, st[color ^ 1].begin()->second);
            }
        } else {
            st[color].erase({r[e.id], e.id});
        }
    }
    cout << dsu.size() << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

