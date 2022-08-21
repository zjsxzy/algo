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
const int maxn = 305;
mint dp[maxn][maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    LL A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<LL> X(m), Y(m);
    set<pair<LL, LL>> st;
    for (int i = 0; i < m; i++) {
        cin >> X[i] >> Y[i];
        st.insert({X[i], Y[i]});
    }
    dp[0][0][0] = 1;
    mint res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            for (int k = 0; i + j + k <= n; k++) {
                LL x = A * i + C * j + E * k;
                LL y = B * i + D * j + F * k;
                if (st.count({x, y})) dp[i][j][k] = 0;
                if (i + j + k == n) res += dp[i][j][k];
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i][j + 1][k] += dp[i][j][k];
                dp[i][j][k + 1] += dp[i][j][k];
            }
        }
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

