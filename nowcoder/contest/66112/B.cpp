#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxV 605
#define maxE 100 * maxV
const int inf = 0x3f3f3f3f;
struct Nod {
    int b, nxt;
    int cap;
    double cst;
    void init(int b, int nxt, int cap, double cst) {
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
    void addCap(int a, int b, int cap, double cst) {
        // cout << a << ' ' << b << ' ' << cap << ' ' << cst << endl;
        buf[len].init(b, E[a], cap, cst);   E[a] = len ++;
        buf[len].init(a, E[b], 0,  -cst);   E[b] = len ++;
    }
    bool spfa(int source, int sink) {
        static queue<int> q;
        // static long long d[maxV];
        // memset(d,  63, sizeof(d));
        vector<double> d(maxV, 1e12);
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
        return d[sink] != 1e12;
    }
    pair<int, double> solve(int source, int sink) {
        double minCost = 0;
        int maxFlow = 0;
        while(spfa(source, sink)) {
            int neck = inf;
            for(int t=p[sink]; t != -1; t = p[ buf[t^1].b ])
                neck = min(neck, buf[t].cap);
            maxFlow += neck;
            for(int t = p[sink]; t != -1; t = p[ buf[t^1].b ]) {
                buf[t].cap -= neck;
                buf[t^1].cap += neck;
                minCost += buf[t].cst * (long long)neck;
            }
        }
        return make_pair(maxFlow, minCost);
    }
} mcmf;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m), weights(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second >> weights[i].first >> weights[i].second;
    }
    auto check = [&](double k) {
        mcmf.init(2 * n + 2);
        int source = 0, sink = 2 * n + 1;
        for (int i = 1; i <= n; i++) {
            mcmf.addCap(source, i, 1, 0);
            mcmf.addCap(i + n, sink, 1, 0);
        }
        for (int i = 0; i < m; i++) {
            mcmf.addCap(edges[i].first, edges[i].second + n, 1, weights[i].second * k - weights[i].first);
        }
        auto res = mcmf.solve(source, sink);
        return res.second < 0;
    };
    double lo = 0, hi = 2e9;
    while (hi - lo > 1e-6) {
        double mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(6) << hi << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}