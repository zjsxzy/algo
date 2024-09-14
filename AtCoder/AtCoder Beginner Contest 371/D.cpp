#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// index from 0
struct Fenwick{
    using T = long long;
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
    int n, q;
    cin >> n;
    vector<int> vec, x(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        vec.push_back(x[i]);
    }
    for (int i = 0; i < n; i++) cin >> p[i];
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        vec.push_back(l[i]);
        vec.push_back(r[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    // for (auto x: vec) cout << x << ' ';
    // cout << endl;
    int m = vec.size();
    vector<int> y(n);
    Fenwick tree(m + 1);
    for (int i = 0; i < n; i++) {
        y[i] = lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin();
        tree.upd(y[i], p[i]);
        // cout << x[i] << ' ' << y[i] << ' ' << p[i] << endl; 
    }
    for (int i = 0; i < q; i++) {
        int L = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
        int R = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin();
        cout << tree.get(L, R) << endl;
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