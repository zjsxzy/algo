#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 5005;
int n, m;
bool vis[MAXN];
vector<pair<int, int> > edges;
vector<int> adj[MAXN];
vector<int> tree;
vector<int> deg;
pair<int, int> del_edge;
vector<int> path;

void dfs(int u) {
    tree.push_back(u);
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve_tree() {
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(1);
    for (auto x : tree) {
        cout << x << " ";
    }
    cout << endl;
}

void dfs2(int u) {
    path.push_back(u);
    vis[u] = true;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        if (u == del_edge.first && v == del_edge.second) continue;
        if (v == del_edge.first && u == del_edge.second) continue;
        dfs2(v);
    }
}

bool compare(vector<int> &res) {
    for (int i = 0; i < n; i++) {
        if (path[i] == res[i]) continue;
        if (path[i] < res[i]) return true;
        else return false;
    }
    return false;
}

void solve_cycle() {
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 2) {
            for (auto v : adj[u]) {
                if (deg[v] == 2 && u < v) {
                    edges.push_back({u, v});
                }
            }
        }
    }
    vector<int> res;
    for (auto e : edges) {
        del_edge = e;
        memset(vis, false, sizeof(vis));
        path.clear();
        dfs2(1);
        if (res.size() == 0 || compare(res)) {
            res = path;
        }
    }
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    deg.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (m == n - 1) {
        solve_tree();
    } else {
        solve_cycle();
    }
    return 0;
}

