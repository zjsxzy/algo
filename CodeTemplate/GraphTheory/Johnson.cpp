const int maxn = 1005;
const int maxm = 50005;
const int inf = 0x3f3f3f3f;
struct Johnson {
    int n, m;
    vector<pair<int, int> > adj[maxn];
    int dis[maxn], d[maxn][maxn], weight[maxn];
 
    Johnson() {}
 
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        for (int i = 0; i <= n; i++) adj[i].clear();
    }
 
    void addEdge(int u, int v, int w) {
        adj[u].PB(MP(v, w));
    }
 
    bool Bellman_Ford(int st) {
        memset(weight, 63, sizeof(weight));
        weight[st] = 0;
        for (int i = 0; i <= n; i++) {
            for (int p = 0; p <= n; p++) {
                for (int j = 0; j < adj[p].size(); j++) {
                    int q = adj[p][j].first, tmp = weight[p] + adj[p][j].second;
                    if (tmp < weight[q]) weight[q] = tmp;
                }
            }
        }
        for (int p = 0; p <= n; p++) {
            for (int j = 0; j < adj[p].size(); j++) {
                int q = adj[p][j].first, tmp = weight[p] + adj[p][j].second;
                if (tmp < weight[q]) return false;
            }
        }
        return true;
    }
 
    void Dijkstra(int st) {
        for (int i = 1; i <= n; i++) {
            dis[i] = inf;
        }
        dis[st] = 0;
        priority_queue<pair<int, int> > pq;
        pq.push(MP(0, st));
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
                if (tmp < dis[v]) {
                    dis[v] = tmp;
                    pq.push(MP(-dis[v], v));
                }
            }
        }
    }
 
    bool solve() {
        for (int i = 1; i <= n; i++) {
            addEdge(0, i, 0);
        }
        if (!Bellman_Ford(0)) return false;
 
        //for (int i = 1; i <= n; i++) printf("%d%c", weight[i], i == n ? '\n' : ' ');
        //re-weighting
        for (int p = 1; p <= n; p++) {
            for (int j = 0; j < adj[p].size(); j++) {
                int q = adj[p][j].first;
                adj[p][j].second += (weight[p] - weight[q]);
                //printf("%d %d %d\n", p, q, adj[p][j].second);
            }
        }
 
        for (int i = 1; i <= n; i++) {
            Dijkstra(i);
            for (int j = 1; j <= n; j++)
                d[i][j] = dis[j] - (weight[i] - weight[j]);
        }
        return true;
    }
 
};