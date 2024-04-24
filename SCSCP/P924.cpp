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
    string S;
    cin >> S;
    int n = S.size();
    S = '#' + S;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        if (S[i] == '0') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
    }
    LL res = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j <= n; j++) {
    //         if (sum[j] - sum[i - 1] >= 0) {
    //             res++;
    //         }
    //     }
    // }
    int mn = *min_element(sum.begin(), sum.end());
    int mx = *max_element(sum.begin(), sum.end());
    // cout << mn << ' ' << mx << endl;
    // for (int i = 0; i <= n; i++) cout << sum[i] << ' ';
    // cout << endl;
    for (int i = 0; i <= n; i++) sum[i] -= mn;
    // for (int i = 0; i <= n; i++) cout << sum[i] << ' ';
    // cout << endl;
    Fenwick tree(mx - mn + 1);
    tree.upd(sum[0], 1);
    for (int i = 1; i <= n; i++) {
        res += tree.get(sum[i]);
        tree.upd(sum[i], 1);
    }
    cout << res << endl;
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