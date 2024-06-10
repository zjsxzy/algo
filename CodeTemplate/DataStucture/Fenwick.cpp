// index from 0
struct Fenwick{
    using T = int;
    vector<T> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, T val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    T get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};


// 区间修改区间查询
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Fenwick d(n + 2), dk(n + 2); // d[i] = a[i] - a[i-1], dk[i] = d[i] * i

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d.upd(i, a[i] - a[i - 1]);
        dk.upd(i, (LL)i * (a[i] - a[i - 1]));
    }

    auto range_upd = [&](int l, int r, LL x) {
        d.upd(l, x);
        d.upd(r + 1, -x);
        dk.upd(l, x * l);
        dk.upd(r + 1, -x * (r + 1));
    };
    auto get_sum = [&](int r) {
        return d.get(r) * (r + 1) - dk.get(r);
    };
    auto range_sum = [&](int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    };

    while (q--) {
        int t, l, r, x;
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> x;
            range_upd(l, r, x);
        } else {
            cin >> l >> r;
            cout << range_sum(l, r) << endl;
        }
    }
}
