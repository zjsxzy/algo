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

// index from 0
struct Fenwick{
    vector<mint> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, mint val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    mint get(int r) {
        mint ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    mint get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void compress(vector<int>& as) {
	vector<int> num;
	for (int i = 0; i < (int)as.size(); i++) {
		num.push_back(as[i]);
	}
	sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i < (int)as.size(); i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    compress(A);
    int m = A.size();
    Fenwick tree(m + 1);
    mint two = 2;
    mint res = 0;
    for (int i = 0; i < m; i++) {
        res += tree.get(A[i]) * two.pow(i);
        tree.upd(A[i], two.pow(i + 1).inverse());
    }
    cout << res << endl;
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

