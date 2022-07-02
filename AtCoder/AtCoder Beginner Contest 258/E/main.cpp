#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q, x;
    cin >> n >> q >> x;
    vector<LL> w(n), sum(2 * n + 1);
    LL s = 0;
    vector<int> g(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        s += w[i];
        sum[i + 1] = sum[i] + w[i];
    }
    LL cnt = 0;
    if (x > s) {
        if (x % s == 0) {
            cnt = x / s - 1;
            x = s;
        } else {
            cnt = x / s;
            x %= s;
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + w[i - n - 1];
    }
    for (int i = 1; i <= n; i++) {
        g[i] = lower_bound(sum.begin(), sum.end(), sum[i - 1] + x) - sum.begin();
        if (g[i] > n) g[i] -= n;
    }
    vector<int> vst(n + 1), f(n + 1), graph;
    int prev = 0, curr = 1, step = 0;
    while (!vst[curr]) {
        graph.push_back(curr);
        f[curr] = step;
        vst[curr] = true;
        prev = curr;
        curr = g[curr] + 1;
        if (curr > n) curr -= n;
        step++;
    }
    /*
    for (auto x: graph) {
        cout << x << "->";
    }
    cout << curr << endl;
    */
    int cycle = f[prev] - f[curr] + 1, path = f[curr];
    // cout << path << ' ' << cycle << endl;
    while (q--) {
        LL k;
        int st, ed;
        cin >> k;
        if (k <= path) {
            st = graph[k - 1];
        } else { // in cycle
            k -= path;
            st = graph[path + (k - 1) % cycle];
        }
        ed = g[st];
        if (ed < st) ed += n;
        cout << cnt * n + ed - st + 1 << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

