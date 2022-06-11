#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<int> pre, in, l, r, pos;
bool flag;

int dfs(int pl, int pr, int il, int ir) {
    // cout << pl << ' ' << pr << ' ' << il << ' ' << ir << endl;
    int cur = pre[pl];
    if (pl == pr && il == ir) {
        return cur;
    }
    int p = pos[cur];
    if (p < il || p > ir) {
        flag = false;
        return 0;
    }
    int len = p - il;
    if (p > il) {
        l[cur] = dfs(pl + 1, pl + len, il, p - 1);
    }
    if (p < ir) {
        r[cur] = dfs(pl + len + 1, pr, p + 1, ir);
    }
    return cur;
}

void solve() {
    cin >> n;
    pre.resize(n + 1); in.resize(n + 1); pos.resize(n + 1);
    l.assign(n + 1, 0); r.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> pre[i];
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    flag = true;
    int res = dfs(1, n, 1, n);
    if (res != 1 || !flag) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << l[i] << ' ' << r[i] << endl;
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


