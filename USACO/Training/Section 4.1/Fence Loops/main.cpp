/*
ID: frankzh1
TASK: fence6
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 205;
const int inf = 1e7;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
int g[maxn][maxn];
vector<pair<int, int>> ed;
vector<int> weight;
int edges, vertexs;

int dijkstra(int st, int ed) {
    vector<int> dist(vertexs, inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (p.first > dist[u]) continue;
        for (int v = 0; v < vertexs; v++) {
            int nd = p.first + g[u][v];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist[ed];
}


void solve() {
    cin >> edges;
    vertexs = 0;
    map<set<int>, int> idx;
    for (int i = 0; i < edges; i++) {
        int cur_edge, w, lnum, rnum;
        cin >> cur_edge >> w >> lnum >> rnum;
        set<int> st;
        st.insert(cur_edge);
        for (int j = 0; j < lnum; j++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        if (idx.find(st) == idx.end()) {
            idx[st] = vertexs++;
        }
        int u = idx[st];
        st.clear();
        st.insert(cur_edge);
        for (int j = 0; j < rnum; j++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        if (idx.find(st) == idx.end()) {
            idx[st] = vertexs++;
        }
        int v = idx[st];
        ed.emplace_back(u, v);
        weight.emplace_back(w);
    }
    for (int i = 0; i < vertexs; i++) {
        for (int j = 0; j < vertexs; j++) {
            g[i][j] = g[j][i] = inf;
        }
    }
    for (int i = 0; i < edges; i++) {
        int u = ed[i].first, v = ed[i].second, w = weight[i];
        g[u][v] = g[v][u] = w;
    }
    int res = inf;
    for (int i = 0; i < edges; i++) {
        int u = ed[i].first, v = ed[i].second, w = weight[i];
        g[u][v] = g[v][u] = inf;
        int d = dijkstra(u, v);
        res = min(res, d + w);
        g[u][v] = g[v][u] = w;
    }
    cout << res << endl;
}

int main() {
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    solve();
    return 0;
}

