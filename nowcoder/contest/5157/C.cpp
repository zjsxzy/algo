#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
// const int MOD = 3*5*7*11*13*17*19*23;
template <int mod>
struct Mod_Int {
    int x;
    Mod_Int() : x(0) {}
    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    static int get_mod() { return mod; }
    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }
    Mod_Int &operator++() { return *this += Mod_Int(1); }
    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }
    Mod_Int &operator--() { return *this -= Mod_Int(1); }
    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }
    Mod_Int operator-() const { return Mod_Int(-x); }
    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }
    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }
    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }
    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }
    bool operator==(const Mod_Int &p) const { return x == p.x; }
    bool operator!=(const Mod_Int &p) const { return x != p.x; }
    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }
    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }
    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};
using mint = Mod_Int<MOD>;

// index from 0
struct Fenwick{
    using T = mint;
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) d[i] = a[i] - a[i - 1];
    Fenwick c(n + 1), kc(n + 1), kkc(n + 1); // a_i, a_i * i, a_i * i * i
    // 三个树状数组单点更新
    auto add = [&](int p, LL x) {
        c.upd(p, x);
        kc.upd(p, x * p % MOD);
        kkc.upd(p, x * p % MOD * p % MOD);
    };
    for (int i = 1; i <= n; i++) {
        add(i, d[i] - d[i - 1]);
    }
    // 区间[l,r]增加首项伟v，公差为d的等差数列
    auto upd = [&](int l, int r, LL v, LL d) {
        add(l, v);
        add(l + 1, d - v);
        add(r + 1, -(v + d * (r - l + 1) % MOD));
        add(r + 2, (v + d * (r - l)) % MOD);
    };
    // 统计a数组[1,r]的区间和
    auto get_sum = [&](LL r) {
        mint s = c.get(r) * (r + 1) * (r + 2);
        s -= kc.get(r) * (2 * r + 3);
        s += kkc.get(r);
        return s / 2;
    };
    // 查询区间[l,r]的和
    auto range_sum = [&](int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    };

    int q;
    cin >> q;
    while (q--) {
        int op, l, r, val, d, m;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> val >> d;
            upd(l, r, val, d);
        } else {
            cin >> l >> r >> m;
            cout << (get_sum(r).x % m - get_sum(l - 1).x % m + m) % m << endl;
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