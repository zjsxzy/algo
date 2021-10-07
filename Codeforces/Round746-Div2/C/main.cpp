#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
int n, k, xs;
int a[maxn], sum[maxn];
bool flag;
vector<int> adj[maxn];

void dfs(int u, int p) {
    sum[u] = a[u];
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(v, u);
            sum[u] ^= sum[v];
        }
    }
}

void search(int u, int p) {
    for (auto v: adj[u]) {
        if (v != p) {
            search(v, u);
            if (sum[v] == xs && !flag) {
                flag = true;
                adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
                return;
            }
        }
    }
}

void solve() {
    cin >> n >> k;
    xs = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cin >> a[i];
        xs ^= a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    if (xs == 0) {
        cout << "YES" << endl;
        return;
    }
    if (k == 2) {
        cout << "NO" << endl;
        return;
    }
    dfs(1, 0);
    flag = false;
    search(1, 0);
    if (flag) {
        flag = false;
        dfs(1, 0);
        search(1, 0);
        if (flag) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

