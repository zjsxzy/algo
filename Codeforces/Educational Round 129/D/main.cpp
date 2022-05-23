#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int leng(unsigned long long x) {
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

void solve() {
    int n;
    unsigned long long x;
    cin >> n >> x;
    queue<unsigned long long> q;
    map<unsigned long long, int> d;
    d[x] = 0;
    q.push(x);
    int res = INT_MAX;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int l = leng(t);
        if (l == n) {
            res = min(res, d[t]);
            continue;
        }
        auto ot = t;
        while (t) {
            unsigned long long nt = ot * (t % 10);
            if (d.find(nt) == d.end()) {
                d[nt] = d[ot] + 1;
                q.push(nt);
            }
            t /= 10;
        }
    }
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
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

