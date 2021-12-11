#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

// index from 0
struct Fenwick{
    vector<int> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void compress(vector<int>& as) {
	vector<int> num;
	for (int i = 0; i < as.size(); i++) {
		num.PB(as[i]);
	}
	sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i < as.size(); i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    compress(a);
    compress(b);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({a[i], b[i]});
    }
    sort(vp.begin(), vp.end());
    Fenwick fen(n + 1);
    LL res = 0;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && vp[i].first == vp[j].first) {
            j++;
        }
        for (int k = i; k < j; k++) {
            fen.upd(vp[k].second, 1);
        }
        for (int k = i; k < j; k++) {
            res += fen.get(vp[k].second, n);
        }
        i = j;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

