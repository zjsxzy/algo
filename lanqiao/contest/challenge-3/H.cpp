#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
const int inf = 1e8;
int n, s, t;
int x[maxn];

struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<edge> adj[maxn + maxn];

int dijkstra(int st, int ed) {
    vector<vector<edge> > adj(n);
    // construct graph: adj[u].emplace_back(v, c)
    vector<int> dist(adj.size(), inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (p.first > dist[v]) continue;
        for (edge e : adj[v]) {
            int nd = p.first + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist[ed];
}

vector<int> primes;

void get_primes() {
    vector<int> vst(n + 1);
    for (int i = 2; i <= 10000; i++) {
        if (!vst[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= 10000; j += i) vst[j] = 1;
        }
    }
}

int calc(int x) {
    int sum = 0;
    for (auto p: primes) {
        if (p > x) break;
        while (x % p == 0) {
            sum += p;
            x /= p;
        }
    }
    if (x > 1) sum += x;
    cout << x << ' ' << sum << endl;
    return sum % n + 1;
}

void solve() {
    cin >> n >> s >> t;
    s--; t--;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        int f = calc(x[i]);
        cout << i << ' ' << x[i] << ' ' << f << endl;
        adj[i].emplace_back(n + f, 1);
        adj[n + f].emplace_back(i, 0);
        adj[i].emplace_back(f, 1);
        adj[f].emplace_back(i, 1);
    }
    int res = dijkstra(s, t);
    cout << res << endl;
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