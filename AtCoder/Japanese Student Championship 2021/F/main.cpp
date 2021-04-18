#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct Fenwick{
    vector<LL> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void update(int pos, LL val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    LL sum(int r) {
        LL ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    LL sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> t(q), x(q), y(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--;
    }

    // compress
    vector<int> num;
    num.push_back(0);
    for (int i = 0; i < y.size(); i++) {
        num.push_back(y[i]);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());

    vector<int> a(n + 1, 0), b(m + 1, 0);
    Fenwick treeA(num.size());
    Fenwick treeB(num.size());
    Fenwick cntA(num.size());
    Fenwick cntB(num.size());

    // init
    cntA.update(0, n);
    cntB.update(0, m);

    LL res = 0;
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            int pos = lower_bound(num.begin(), num.end(), a[x[i]]) - num.begin();
            res -= cntB.sum(pos) * a[x[i]];
            res -= treeB.sum(pos + 1, num.size() - 1);
            treeA.update(pos, -a[x[i]]);
            cntA.update(pos, -1);

            // modify
            a[x[i]] = y[i];
            pos = lower_bound(num.begin(), num.end(), a[x[i]]) - num.begin();
            treeA.update(pos, a[x[i]]);
            cntA.update(pos, 1);
            res += cntB.sum(pos) * a[x[i]];
            res += treeB.sum(pos + 1, num.size() - 1);
        } else {
            int pos = lower_bound(num.begin(), num.end(), b[x[i]]) - num.begin();
            res -= cntA.sum(pos) * b[x[i]];
            res -= treeA.sum(pos + 1, num.size() - 1);
            treeB.update(pos, -b[x[i]]);
            cntB.update(pos, -1);

            // modify
            b[x[i]] = y[i];
            pos = lower_bound(num.begin(), num.end(), b[x[i]]) - num.begin();
            treeB.update(pos, b[x[i]]);
            cntB.update(pos, 1);
            res += cntA.sum(pos) * b[x[i]];
            res += treeA.sum(pos + 1, num.size() - 1);
        }
        cout << res << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

