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

template<int MOD>
struct ModInt {
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    inline int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % (unsigned long long)MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % (unsigned long long)MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % (unsigned long long)MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }
    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
};
const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
