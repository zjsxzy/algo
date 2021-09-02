/*
ID: frankzh1
TASK: job
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct machine {
    int id, tim;
    bool operator < (const machine& p) const {
        return tim > p.tim;
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> a(m1), b(m2);
    for (int i = 0; i < m1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m2; i++) {
        cin >> b[i];
    }
    priority_queue<machine> pq;
    for (int i = 0; i < m1; i++) {
        pq.push((machine){i, a[i]});
    }
    vector<int> f(n);
    int ansa = 0;
    for (int i = 0; i < n; i++) {
        auto x = pq.top(); pq.pop();
        f[i] = x.tim;
        pq.push((machine){x.id, x.tim + a[x.id]});
        ansa = max(ansa, f[i]);
    }
    while (!pq.empty()) pq.pop();
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    for (int i = 0; i < m2; i++) {
        pq.push((machine){i, b[i]});
    }
    int ansb = 0;
    for (int i = 0; i < n; i++) {
        auto x = pq.top(); pq.pop();
        ansb = max(ansb, f[i] + x.tim);
        pq.push((machine){x.id, x.tim + b[x.id]});
    }
    cout << ansa << " " << ansb << endl;
}

int main() {
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    solve();
    return 0;
}

