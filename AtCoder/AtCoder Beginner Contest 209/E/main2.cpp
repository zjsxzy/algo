#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 500000;
vector<int> adj[MAXN];
int win[MAXN], outdeg[MAXN];

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> idx;
    int m = 0;
    memset(outdeg, 0, sizeof(outdeg));
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
        outdeg[idx[prefix]]++;
    }
    vector<int> q;
    memset(win, 0, sizeof(win));
    for (int i = 0; i < m; i++) {
        if (outdeg[i] == 0) {
            win[i] = 1;
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.back(); q.pop_back();
        for (auto &v: adj[u]) {
            if (win[v] != 0) continue;
            if (win[u] == 1) {
                win[v] = -1;
                outdeg[v] = 0;
                q.push_back(v);
            }
            if (win[u] == -1) {
                if (outdeg[v]) outdeg[v]--;
                if (!outdeg[v]) {
                    win[v] = 1;
                    q.push_back(v);
                }
            }
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

