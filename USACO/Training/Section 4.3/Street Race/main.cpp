/*
ID: frankzh1
TASK: race3
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
vector<int> adj[maxn];
int n;

void dfs(int u, vector<bool>& vis) {
    for (auto &v: adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, vis);
        }
    }
}

void solve() {
    int a, i = 0;
    while (cin >> a) {
        if (a == -1) break;
        while (a >= 0) {
            adj[i].emplace_back(a);
            cin >> a;
        }
        i++;
    }
    n = i - 1;

    // question 1
    vector<int> res;
    for (int i = 1; i < n; i++) {
        vector<bool> vis(n + 1);
        vis[i] = true;
        dfs(0, vis);
        if (!vis[n]) res.emplace_back(i);
    }
    cout << res.size();
    for (auto &x: res) {
        cout << " " << x;
    }
    cout << endl;

    // question 2
    vector<int> ans;
    for (auto &i: res) {
        vector<bool> vis(n + 1), vst(n + 1);
        dfs(i, vst);
        vis[i] = true;
        vis[0] = true;
        dfs(0, vis);
        bool flag = true;
        for (int j = 0; j <= n; j++) {
            if (j != i && vis[j] && vst[j]) {
                flag = false;
                break;
            }
        }
        if (flag) ans.emplace_back(i);
    }
    cout << ans.size();
    for (auto &x: ans) {
        cout << " " << x;
    }
    cout << endl;
}

int main() {
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    solve();
    return 0;
}

