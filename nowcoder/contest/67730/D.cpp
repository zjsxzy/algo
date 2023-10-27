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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    Fenwick tree1(n + 1), tree2(n + 1);
    for (int i = 1; i <= m; i++) {
        tree1.upd(cnt[i], 1);
        tree2.upd(cnt[i], cnt[i]);
    }
    for (int i = 1; i <= m; i++) {
        if (cnt[i] > n - k) {
            cout << -1 << ' ';
            continue;
        }
        tree1.upd(cnt[i], -1);
        tree2.upd(cnt[i], -cnt[i]);
        auto check = [&](int x) {
            int sum = tree1.get(x + 1, n) * x + tree2.get(x);
            return sum + cnt[i] >= n - k;
        };
        int lo = 0, hi = n - k - cnt[i], res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) hi = mid - 1, res = mid;
            else lo = mid + 1;
        }
        cout << res << ' ';
        tree1.upd(cnt[i], 1);
        tree2.upd(cnt[i], cnt[i]);
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