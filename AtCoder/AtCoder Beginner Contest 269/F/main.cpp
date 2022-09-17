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

void solve() {
    LL n, m;
    cin >> n >> m;

    auto query = [&](LL A, LL B, LL C, LL D) {
        if ((A + C) & 1) C++;
        if (!((A + D) & 1)) D++;
        LL num = (D - C + 1) / 2;
        mint a = A, c = C, d = D;
        mint st = (a - 1) * m + c, ed = (a - 1) * m + d;
        // cout << st << ' ' << ed << ' ' << num << ' ' << endl;
        mint sum = (st + ed) * (ed - st + 1) / 2;
        mint res = (sum - num) / 2;
        // cout << res << endl;
        LL rows = (B - A + 2) / 2;
        // cout << A << ' ' << B << ' ' << rows << endl;
        mint one = 1;
        mint ans = res * rows + one * (0 + (rows - 1) * 2) * rows / 2 * m * num;
        //cout << ans << endl;
        //cout << endl;
        return ans;
    };
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mint x = query(a, b, c, d);
        mint y;
        if (b > a) y = query(a + 1, b, c, d);
        cout << x + y << endl;
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

