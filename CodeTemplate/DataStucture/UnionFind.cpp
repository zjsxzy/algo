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
