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
#include <cassert>
#include <climits>
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

const int maxm = 200005;
int n, m;
int u[maxm], v[maxm], c[maxm], vis[maxm];
vector<pair<int, int> > adj[maxm];

void output() {
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << endl;
    }
}

void dfs(int p) {
    for (auto e : adj[p]) {
        if (!vis[e.first]) {
            if (e.second != vis[p]) {
                vis[e.first] = e.second;
            } else {
                vis[e.first] = e.second == 1 ? 2 : 1;
            }
            dfs(e.first);
        }
    }
}

void solve() {
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dfs(1);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        output();
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        adj[u[i]].push_back({v[i], c[i]});
        adj[v[i]].push_back({u[i], c[i]});
    }
    solve();
    return 0;
}


