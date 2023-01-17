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
        if (l == 0) return get(r);
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<Fenwick> tree(26, Fenwick(n));
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        tree[s[i] - 'a'].upd(i, 1);
    }
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            char c;
            cin >> x >> c;
            x--;
            tree[s[x] - 'a'].upd(x, -1);
            cnt[s[x] - 'a']--;
            s[x] = c;
            tree[c - 'a'].upd(x, 1);
            cnt[c - 'a']++;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            vector<int> sum(26);
            for (int i = 0; i < 26; i++) {
                sum[i] = tree[i].get(l, r);
                // if (sum[i] > 0) {
                    // cout << (char)('a' + i) << ' ' << sum[i] << endl;
                // }
            }
            int a = 0, b = 25;
            while (!sum[a]) a++;
            while (!sum[b]) b--;
            // cout << (char)('a' + a) << ' ' << (char)('a' + b) << endl;
            bool flag = true;
            for (int i = a + 1; i < b; i++) {
                if (cnt[i] != sum[i]) {
                    flag = false;
                    break;
                }
            }
            int curr = l;
            for (int i = 0; i < 26; i++) {
                // cout << (char)('a' + i) << ' ' << curr << ' ' << curr + sum[i] << ' ' << tree[i].get(curr, curr + sum[i]) << ' ' << sum[i] << endl;
                if (tree[i].get(curr, curr + sum[i] - 1) != sum[i]) {
                    flag = false;
                    break;
                }
                curr += sum[i];
            }
            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}