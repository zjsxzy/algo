#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
struct nod {
    int type, x, id, d, y;
    // type: 0: segment, 1: point
    nod(int type_, int x_, int id_, int d_, int y_) {
        type = type_;
        x = x_;
        id = id_;
        d = d_;
        y = y_;
    } 
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<nod> vec;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        vec.emplace_back(0, l[i], -1, 0, r[i]);
        vec.emplace_back(0, r[i] + 1, -1, 1, l[i]);
    }
    vector<int> ans(q), a(q), b(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        vec.emplace_back(1, a[i], i, 0, b[i]);
    }

    // how many segments contains a
    sort(vec.begin(), vec.end(), 
        [](const nod& A, const nod& B){
            if (A.x == B.x) return A.type < B.type;
            return A.x < B.x;
        });
    int curr = 0;
    for (auto v: vec) {
        if (v.type == 0) {
            if (v.d == 0) curr++;
            else curr--;
        } else {
            if (v.d == 0) ans[v.id] += curr;
        }
    }
    // for (int i = 0; i < q; i++) cout << ans[i] << endl;
    vec.clear();

    // how many segments contains both a and b
    for (int i = 0; i < n; i++) {
        vec.emplace_back(0, l[i], -1, 0, r[i]);
        vec.emplace_back(0, r[i] + 1, -1, 1, l[i]);
    }
    for (int i = 0; i < q; i++) {
        vec.emplace_back(1, min(a[i], b[i]), i, 0, max(a[i], b[i]));
    }
    sort(vec.begin(), vec.end(), 
        [](const nod& A, const nod& B){
            if (A.x == B.x) return A.type < B.type;
            return A.x < B.x;
        });
    Fenwick tree(2e5 + 5);
    for (auto v: vec) {
        if (v.type == 0) {
            if (v.d == 0) tree.upd(v.y, 1);
        } else {
            ans[v.id] -= tree.get(v.y, 2e5);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
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