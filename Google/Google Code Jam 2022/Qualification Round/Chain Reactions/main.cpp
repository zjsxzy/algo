#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> F(n + 1), dp(n + 1), deg(n + 1), p(n + 1);
    vector<LL> sdp(n + 1);
    vector<vector<int>> adj(n + 1), rev(n + 1);
    for (int i = 1; i <= n; i++) cin >> F[i];
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        p[u] = v;
        adj[u].push_back(v);
        rev[v].push_back(u);
        deg[v]++;
    }

    // bruteforce
    if (n > 10) {
        cout << 1 << endl;
        return;
    }
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            order.push_back(i);
        }
    }
    sort(order.begin(), order.end());
    LL res = 0;
    do {
        LL sum = 0;
        vector<bool> vst(n + 1);
        for (auto start: order) {
            int mx = F[start], curr = start;
            while (curr != 0) {
                if (!vst[curr]) {
                    mx = max(mx, F[curr]);
                    vst[curr] = true;
                }
                curr = p[curr];
            }
            sum += (LL)mx;
        }
        res = max(res, sum);
    } while (next_permutation(order.begin(), order.end()));
    cout << res << endl;

    // dp
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (rev[u].size() == 0) { // initiators
            dp[u] = sdp[u] = F[u];
        } else {
            int mn = INT_MAX;
            for (auto rv: rev[u]) mn = min(mn, dp[rv]);
            if (F[u] > mn) {
                sdp[u] += (LL)(F[u] - mn);
            }
            dp[u] = max(dp[u], F[u]);
        }
        for (auto v: adj[u]) {
            dp[v] = max(dp[v], dp[u]);
            sdp[v] += sdp[u];
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    cout << sdp[0] << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        printf("Case #%d: \n", cs);
        solve();
    }
    return 0;
}

