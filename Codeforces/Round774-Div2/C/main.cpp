#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    map<LL, int> dist;
    vector<LL> val;
    queue<LL> q;
    for (int i = 0; i < 60; i++) {
        if ((1LL << i) > 1e12) break;
        q.push(1LL << i);
        val.push_back(1LL << i);
        dist[1LL << i] = 1;
    }
    LL prod = 1;
    for (int i = 2; i <= 20; i++) {
        prod *= i;
        if (prod > 1e12) break;
        q.push(prod);
        val.push_back(prod);
        dist[prod] = 1;
    }
    cout << val.size() << endl;
    return;
    while (!q.empty()) {
        LL t = q.front(); q.pop();
        cout << t << " " << dist[t] << endl;
        for (auto& v: val) {
            LL tt = t + v;
            if (tt > 1e12) continue;
            if (dist.find(tt) == dist.end()) {
                dist[tt] = dist[t] + 1;
                q.push(tt);
            }
        }
    }
    int ts;
    cin >> ts;
    while (ts--) {
        LL n;
        cin >> n;
        if (dist.find(n) == dist.end()) {
            cout << -1 << endl;
        } else {
            cout << dist[n] << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

