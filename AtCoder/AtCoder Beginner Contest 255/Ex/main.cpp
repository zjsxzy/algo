#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
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

template <typename T>
struct lazy_segment_tree {
    int N;
    vector<T> sum, ST, lazy;
    lazy_segment_tree(vector<T> &A) {
        int N2 = A.size();
        N = 1;
        while (N < N2) {
            N *= 2;
        }
        sum = vector<T>(N * 2 - 1, 0);
        for (int i = 0; i < N2; i++) {
            sum[N - 1 + i] = A[i];
        }
        for (int i = N - 2; i >= 0; i--) {
            sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
        }
        ST = vector<T>(N * 2 - 1, 0);
        lazy = vector<T>(N * 2 - 1, -1);
    }
    void eval(int i) {
        if (lazy[i] != -1) {
            if (i < N - 1) {
                lazy[i * 2 + 1] = lazy[i];
                lazy[i * 2 + 2] = lazy[i];
            }
            ST[i] = sum[i] * lazy[i];
            lazy[i] = -1;
        }
    }
    void range_update(int L, int R, T x, int i, int l, int r) {
        eval(i);
        if (r <= L || R <= l) {
            return;
        } else if (L <= l && r <= R) {
            lazy[i] = x;
            eval(i);
        } else {
            int m = (l + r) / 2;
            range_update(L, R, x, i * 2 + 1, l, m);
            range_update(L, R, x, i * 2 + 2, m, r);
            ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
        }
    }
    void range_update(int L, int R, T x) {
        range_update(L, R, x, 0, 0, N);
    }
    T range_sum(int L, int R, int i, int l, int r) {
        eval(i);
        if (r <= L || R <= l) {
            return 0;
        } else if (L <= l && r <= R) {
            return ST[i];
        } else {
            int m = (l + r) / 2;
            return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
        }
    }
    T range_sum(int L, int R) {
        return range_sum(L, R, 0, 0, N);
    }
};

void solve() {
    LL N;
    int Q;
    cin >> N >> Q;
    vector<LL> D(Q), L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        cin >> D[i] >> L[i] >> R[i];
        L[i]--;
    }
    vector<LL> X;
    X.push_back(0);
    for (int i = 0; i < Q; i++) {
        X.push_back(L[i]);
        X.push_back(R[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    vector<LL> L2(Q), R2(Q);
    for (int i = 0; i < Q; i++) {
        L2[i] = lower_bound(X.begin(), X.end(), L[i]) - X.begin();
        R2[i] = lower_bound(X.begin(), X.end(), R[i]) - X.begin();
    }
    int cnt = X.size();
    vector<mint> W(cnt - 1);
    for (int i = 0; i < cnt - 1; i++) {
        mint l = X[i] + 1, r = X[i + 1];
        W[i] = (l + r) * (r - l + 1) / 2;
    }
    vector<mint> S(cnt);
    for (int i = 0; i < cnt - 1; i++) {
        S[i + 1] = S[i] + W[i];
    }
    lazy_segment_tree<mint> ST(W);
    for (int i = 0; i < Q; i++) {
        mint res = (S[R2[i]] - S[L2[i]]) * D[i] - ST.range_sum(L2[i], R2[i]);
        cout << res << endl;
        ST.range_update(L2[i], R2[i], D[i]);
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


