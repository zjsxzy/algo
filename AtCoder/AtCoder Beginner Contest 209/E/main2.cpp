#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 500000;
vector<int> adj[MAXN];
int win[MAXN], deg[MAXN];

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> idx;
    int m = 0;
    memset(deg, 0, sizeof(deg));
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
        adj[idx[suffix]].push_back(idx[prefix]);
        deg[idx[prefix]]++;
    }
    vector<int> q;
    memset(win, 0, sizeof(win));
    for (int i = 0; i < m; i++) {
        if (deg[i] == 0) {
            win[i] = 1;
            q.push(i);
        }
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

