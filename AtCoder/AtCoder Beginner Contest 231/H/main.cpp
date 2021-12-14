#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define maxV 2005
#define maxE 100 * maxV
const LL inf = (1LL <<60);
struct Nod {
    int b, nxt;
    LL cap, cst;
    void init(int b, int nxt, LL cap, LL cst) {
        this->b = b;
        this->nxt = nxt;
        this->cap = cap;
        this->cst = cst;
    }
};
struct MinCost {
    int E[maxV];        int n;
    Nod buf[maxE*2];    int len;

    int p[maxV];
    void init(int n) {
        this->n = n;
        memset(E, 255, sizeof(E));
        len = 0;
    }
    void addCap(int a, int b, LL cap, LL cst) {
        buf[len].init(b, E[a], cap, cst);   E[a] = len ++;
        buf[len].init(a, E[b], 0,  -cst);   E[b] = len ++;
    }
    bool spfa(int source, int sink) {
        static queue<int> q;
        static LL d[maxV];
        // memset(d,  63, sizeof(d));
        for (int i = 0; i < n; i++) {
            d[i] = inf;
        }
        memset(p, 255, sizeof(p));

        d[source] = 0;
        q.push(source);
        int u, v;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int i = E[u]; i != -1; i = buf[i].nxt) {
                v = buf[i].b;
                if(buf[i].cap>0 && d[u]+buf[i].cst<d[v]) {
                    d[v] = d[u]+buf[i].cst;
                    p[v] = i;
                    q.push(v);
                }
            }
        }
        return d[sink] != inf;
    }
    pair<LL, LL> solve(int source, int sink) {
        LL minCost = 0, maxFlow = 0;
        while(spfa(source, sink)) {
            LL neck = inf;
            for(int t=p[sink]; t != -1; t = p[ buf[t^1].b ])
                neck = min(neck, buf[t].cap);
            maxFlow += neck;
            for(int t = p[sink]; t != -1; t = p[ buf[t^1].b ]) {
                buf[t].cap -= neck;
                buf[t^1].cap += neck;
                minCost += buf[t].cst * neck;
            }
        }
        return make_pair(maxFlow, minCost);
    }
} mcmf;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    int source = 0, sink = h + w + 1, cen = sink + 1;
    mcmf.init(cen + 1);
    for (int i = 1; i <= h; i++) {
        mcmf.addCap(source, i, 1, 0);
    }
    for (int j = 1; j <= w; j++) {
        mcmf.addCap(h + j, sink, 1, 0);
    }
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        mcmf.addCap(x, h + y, 1, c);
        mcmf.addCap(cen, h + y, 1, c);
        mcmf.addCap(x, cen, 1, c);
    }
    if (w > h) mcmf.addCap(source, cen, w - h, 0);
    else mcmf.addCap(cen, sink, h - w, 0);
    auto res = mcmf.solve(source, sink);
    // cout << res.first << endl;
    cout << res.second << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

