#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 500000;
vector<int> adj[MAXN];
int win[MAXN], vst[MAXN];

void dfs(int u) {
    vst[u] = 1;
    if (adj[u].size() == 0) {
        win[u] = 1;
        return;
    }
    for (auto &v: adj[u]) {
        if (!vst[v]) {
            dfs(v);
        }
    }
    bool flag = false;
    for (auto &v: adj[u]) {
        if (win[v] == 1) {
            win[u] = -1;
            return;
        }
        if (win[v] != -1) {
            flag = true;
        }
    }
    if (!flag) win[u] = 1;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> idx;
    int m = 0;
    for (auto &x: s) {
        cin >> x;
        string prefix = x.substr(0, 3);
        if (idx.find(prefix) == idx.end()) {
            idx[prefix] = m;
            m++;
        }
        string suffix = x.substr(x.size() - 3, 3);
        if (idx.find(suffix) == idx.end()) {
            idx[suffix] = m;
            m++;
        }
        adj[idx[prefix]].push_back(idx[suffix]);
    }
    memset(win, 0, sizeof(win));
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i < m; i++) {
        dfs(i);
    }
    /*
    for (auto &[k, v]: idx) {
        cout << k << " " << v << " " << win[v] << endl;
    }
    */
    for (auto &x: s) {
        string suffix = x.substr(x.size() - 3, 3);
        if (win[idx[suffix]] == 1) cout << "Takahashi" << endl;
        else if (win[idx[suffix]] == -1) cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

