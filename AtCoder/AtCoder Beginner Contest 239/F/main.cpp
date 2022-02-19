#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
int n, m;
vector<int> adj[maxn];
int d[maxn];

void solve() {
    cin >> n >> m;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        sum += (LL)d[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (2 * (n - m - 1) != sum - 2 * m) {
        cout << -1 << endl;
        return;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

