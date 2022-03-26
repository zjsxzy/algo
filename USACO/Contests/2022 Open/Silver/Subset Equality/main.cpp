#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
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
string s, t;
int q, n, m;
string query[maxn];
vector<int> spos[26], tpos[26];
vector<Fenwick> stree, ttree;
map<string, int> tree_idx;
int trees;

bool find(string& que, string& pref) {
    int idx = tree_idx[pref];
    Fenwick ts = stree[idx], tt = ttree[idx];
    for (int i = 0; i < que.size(); i++) {
        int c = que[i] - 'a';
        if (spos[c].size() != tpos[c].size()) {
            return false;
        } else {
            int n = spos[c].size();
            for (int j = 0; j < n; j++) {
                int ps = spos[c][j], pt = tpos[c][j];
                int sums = ts.get(ps), sumt = tt.get(pt);
                if (sums != sumt) return false;
                ts.upd(ps, 1); tt.upd(pt, 1);
            }
        }
    }
    tree_idx[que] = trees;
    trees++;
    stree.push_back(ts);
    ttree.push_back(tt);
    return true;
}

void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) {
        spos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        tpos[t[i] - 'a'].push_back(i);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }
    Fenwick ts(n), tt(m);
    trees = 0;
    tree_idx[""] = trees;
    stree.push_back(ts);
    ttree.push_back(tt);
    map<string, bool> mp;
    for (int i = 0; i < q; i++) {
        string pref = query[i].substr(0, query[i].size() - 1);
        // cout << query[i] << " " << pref << endl;
        while (pref.size() > 0 && mp.find(pref) == mp.end()) {
            pref = pref.substr(0, pref.size() - 1);
        }
        if (pref.size() != 0 && !mp[pref]) {
            cout << "N";
            mp[query[i]] = false;
        } else {
            bool res = find(query[i], pref);
            if (res) cout << "Y";
            else cout << "N";
            mp[query[i]] = res;
        }
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

