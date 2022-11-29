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

// directional dsu
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    // merge y into x
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

// with solution
struct union_find {
    int n;
    vector<set<int>> groups;
    vector<int> owner;
    union_find(int n_) : n(n_){
        groups.assign(n, {});
        owner.resize(n);
        for (int i = 0; i < n; i++) {
            owner[i] = i;
            groups[i] = {i};
        }
    }
    void unite(int a, int b) {
        a = owner[a];
        b = owner[b];
        if (a == b) return;
        if (groups[a].size() > groups[b].size()) swap(a, b);
        for (int x : groups[a]) {
            owner[x] = b;
            groups[b].insert(x);
        }
        groups[a].clear();
    }
}

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(par.size());
        for (int i = 0; i < int(par.size()); ++i) ret[find(i)].push_back(i);
        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<int> &v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};

void left_and_right(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = nums[i];
    }
    vector<int> left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {
        left[i] = i - 1;
        while (left[i] >= 1 && a[left[i]] >= a[i]) {
            left[i] = left[left[i]];
        }
    }
    for (int i = n; i >= 1; i--) {
        right[i] = i + 1;
        while (right[i] <= n && a[right[i]] >= a[i]) {
            right[i] = right[right[i]];
        }
    }
}
