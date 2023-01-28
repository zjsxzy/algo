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
    string s, t;
    cin >> s >> t;
    string ss = s.substr(s.size() - t.size(), t.size());
    int n = t.size();
    Fenwick tree(n);
    auto match = [&](char a, char b) {
        if (a != '?' && b != '?' && a != b) return 0;
        return 1;
    };
    bool flag = true;
    for (int i = 0; i < n; i++) {
        tree.upd(i, match(ss[i], t[i]));
    }
    if (tree.get(n - 1) == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int i = 0; i < n; i++) {
        tree.upd(i, -match(ss[i], t[i]));
        tree.upd(i, match(s[i], t[i]));
        if (tree.get(n - 1) == n) cout << "Yes" << endl;
        else cout << "No" << endl;
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