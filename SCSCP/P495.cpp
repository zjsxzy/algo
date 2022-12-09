#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
int n;
int a[maxn];
vector<int> adj[maxn];
map<int, LL> mp[maxn];
LL ans[maxn];

bool compare (const pair<int, LL>&a, const pair<int, LL>&b) {
   return a.second < b.second;
}

void dfs(int u, int fa) {
    for (auto& v: adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (auto& [k, v]: mp[v]) {
            mp[u][k] += v;
        }
    }
    mp[u][a[u]]++;
    ans[u] = 0;
    auto m = max_element(mp[u].begin(), mp[u].end(), compare);
    for (auto &[k, v]: mp[u]) {
        if (v == m->second) ans[u] += k;
    }
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[i].PB(p);
        adj[p].PB(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i == n) cout << endl;
        else cout << " ";
    }
}

int main() {
    solve();
    return 0;
}

