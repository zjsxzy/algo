#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int P = 3*5*7*11*13*17*19*23;
// index from 0
struct Fenwick{
    using T = LL;
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
            tree[pos] %= P;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
            ans %= P;
        }
        return ans;
    }
};

// 扩展欧几里得求逆元，b不为质数
void exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x, y;
    exgcd(2, P, x, y);
    int inv2 = x > 0 ? x : y - x; // 求2的逆元，注意P不为质数，只能通过扩展欧几里得求逆元

    Fenwick c(n + 1), kc(n + 1), kkc(n + 1); // a_i, a_i * i, a_i * i * i
    // 三个树状数组单点更新
    auto add = [&](int p, LL x) {
        c.upd(p, x);
        kc.upd(p, x * p % P);
        kkc.upd(p, x * p % P * p % P);
    };
    // 区间[l,r]增加首项伟v，公差为d的等差数列
    auto upd = [&](int l, int r, LL v, LL d) {
        add(l, v);
        add(l + 1, d - v);
        add(r + 1, -(v + d * (r - l + 1) % P));
        add(r + 2, (v + d * (r - l) % P) % P);
    };
    // 统计a数组[1,r]的区间和
    auto get_sum = [&](LL r) {
        LL s = c.get(r) * (r + 1) % P * (r + 2) % P;
        s = (s - kc.get(r) * (2 * r + 3) % P + P) % P;
        s = (s + kkc.get(r)) % P;
        return s % P * inv2 % P;
    };
    for (int i = 1; i <= n; i++) {
        upd(i, i, a[i], 0);
    }

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
            LL ans = (get_sum(r) - get_sum(l - 1) + m) % m;
            cout << (ans + m) % m << endl;
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