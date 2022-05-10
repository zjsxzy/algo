#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int>> adj;
string color;
vector<pair<int, int>> cnt;

void dfs(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u].first += cnt[v].first;
        cnt[u].second += cnt[v].second;
    }
    if (color[u] == 'B') cnt[u].first++;
    else cnt[u].second++;
}

void solve() {
    int n;
    cin >> n;
    cnt.assign(n, {0, 0});
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    cin >> color;
    dfs(0, -1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i].first == cnt[i].second) res++;
    }
    cout << res << endl;
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

