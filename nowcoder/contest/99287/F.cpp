#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    Fenwick tree(n + 1);
    vector<LL> odd(n + 1), even(n + 1), odd_sum(n + 1), even_sum(n + 1);
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int biger = tree.get(a[i] + 1, n);
        if (i & 1) {
            res += 1ll * biger * odd[a[i]] - odd_sum[a[i]];
            res += 2ll * (biger * even[a[i]] - even_sum[a[i]]);
        } else {
            res += 1ll * biger * even[a[i]] - even_sum[a[i]];
            res += 2ll * (biger * odd[a[i]] - odd_sum[a[i]]);
        }
        if (i & 1) {
            odd[a[i]]++;
            odd_sum[a[i]] += biger;
        } else {
            even[a[i]]++;
            even_sum[a[i]] += biger;
        }
        tree.upd(a[i], 1);
    }
    cout << res << '\n';
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