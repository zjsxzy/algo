#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}  // namespace atcoder
using namespace atcoder;
int op(int a, int b) {
    return max(a, b);
}
int e() {
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n), dfn(n), siz(n);
    int cnt = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
        dep[u] = d;
        dfn[u] = cnt++;
        siz[u]++;
        for (auto v: g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + 1);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1, 0);
    int maxdep = *max_element(dep.begin(), dep.end());
    vector<vector<pair<int, int>>> weight(maxdep + 1);
    for (int i = 0; i < n; i++) {
        weight[dep[i]].emplace_back(dfn[i], w[i]);
    }
    vector<int> ans(q);
    vector<vector<pair<int, int>>> query(maxdep + 1);
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        query[dep[x] + k].emplace_back(x, i);
    }

    segtree<int, op, e> tree(n);
    for (int d = 0; d <= maxdep; d++) {
        if (query[d].empty()) continue;
        for (auto [i, wi]: weight[d]) {
            tree.set(i, wi);
        }
        for (auto [x, i]: query[d]) {
            ans[i] = tree.prod(dfn[x] + 1, dfn[x] + siz[x]);
        }
        for (auto [i, wi]: weight[d]) {
            tree.set(i, 0);
        }
    }
    for (auto x: ans) cout << x << endl;
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