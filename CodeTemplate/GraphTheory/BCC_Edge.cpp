/*
 * Find BCC, size is the number of bcc, if id[u]=id[v], it means u and v are in the same bcc
 */
const int maxn = 5005;
vector<pair<int, int> > graph[maxn];
int dfn[maxn], low[maxn], id[maxn], deg[maxn];
bool visit[maxn];
int N, M, size;
stack<int> S;

void Tarjan(int u, int dep) {
    dfn[u] = low[u] = dep;
	S.push(u);
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        int id = graph[u][i].second;
        if (dfn[v] == -1) {
            visit[id] = true;//It's an undirected graph
            Tarjan(v, dep + 1);
            low[u] = min(low[u], low[v]);
			//if (low[v] > dfn[u]) tag[id] = 1;
        } else if (!visit[id]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
	if (low[u] == dfn[u]) {
		size++;
		int v;
		do {
			v = S.top();
			S.pop();
			id[v] = size;
		} while (u != v);
	}
}

void BCC() {
	while (!S.empty())
		S.pop();
	memset(id, -1, sizeof(id));
    for (int i = 0; i < N; i++)
        dfn[i] = -1;
    for (int i = 0; i < N; i++)
        if (dfn[i] == -1) Tarjan(i, 0);
}
