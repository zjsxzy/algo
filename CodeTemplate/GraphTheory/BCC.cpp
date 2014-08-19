struct BCC {
// Observation 1: An internal vertex u of the DFS tree (other than the root) is an articulation point 
// if and only there exists a subtree rooted at a child of u such that there is no back edge from any vertex in this subtree to a proper ancestor of u.
// Observation 3: The root of the DFS is an articulation point if and only if it has two or more children.
    #define WHITE 0
    #define GRAY 1
    int n, Time, cntChild, nBcc;
    int color[maxn], dfn[maxn], low[maxn], pred[maxn];
    int id[maxn], tot[maxn];
    vector<int> adj[maxn];
    set<int> ArtPt;
    set<pair<int, int> > ArtEd;

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++)
            adj[i].clear();
    }

    void addEdge(int u, int v) {
        adj[u].PB(v);
        adj[v].PB(u);
    }

    void dfs(int u) {
        color[u] = GRAY;
        low[u] = dfn[u] = ++Time;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (color[v] == WHITE) {                // (u,v) is a tree edge
                pred[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);       // update Low[u]
                if (low[v] > dfn[u]) {
                    ArtEd.insert(MP(u, v));
                    ArtEd.insert(MP(v, u));
                }
                if (pred[u] == -1) {                // root: apply Observation 3
                    cntChild++;
                    if (cntChild == 2) {
                        ArtPt.insert(u);
                    }
                } else if (low[v] >= dfn[u]) {      // internal node: apply Observation 1
                    ArtPt.insert(u);
                }
            } else if (pred[u] != v) {              // (u,v) is a back edge
                low[u] = min(low[u], dfn[v]);       // update Low[u]
            }
        }
    }

    void solve() {
        nBcc = 0;
        Time = 0;
        cntChild = 0;
        memset(pred, -1, sizeof(pred));
        memset(color, 0, sizeof(color));
        memset(id, -1, sizeof(id));
        memset(tot, 0, sizeof(tot));
        ArtPt.clear();
        ArtEd.clear();
        for (int i = 0; i < n; i++)
            if (color[i] == WHITE) dfs(i);

        for (int i = 0; i < n; i++) {
            if (id[i] == -1) {
                id[i] = nBcc;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    tot[nBcc]++;
                    for (int j = 0; j < adj[u].size(); j++) {
                        int v = adj[u][j];
                        if (id[v] == -1 && ArtEd.find(MP(u, v)) == ArtEd.end()) {
                            id[v] = nBcc;
                            q.push(v);
                        }
                    }
                }
                nBcc++;
            }
        }
    }
} bcc;

/**
 * 求解双连通分支！两点之间可以有重边，这样的话会将两点设为一个连通分支里面，但还是要甚用重边！
 * 所点后的树不会有重边！！
 * 缩点后的树的边也是关于^对偶
 * 判断某边是否为桥的方法是：id[a]!=id[b]并且brg[该边]=壹
 * 并查集+LCA也可以解决双连通分支，而且是动态的！
 */
#define maxn 1010
#define maxm 10100
struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		this->b = b;
		this->nxt = nxt;
	}
};
struct BCC {
	int E[maxn];		int n;			///原始图[0, n)
	Nod buf[maxm*2];	int len;		///资源
	
	bool brg[maxm*2];					///某边是否是桥
	bool cut[maxn];						///某点是否为割点
	int id[maxn];						///某点所在分支的编号
	
	int EBcc[maxn];		int nBcc;		///缩点后的图
	Nod bufBcc[maxn*2];	int lenBcc;		///缩点后的资源2*maxn足够！
	int tot[maxn];						///某个bcc包含的点数
	//以上变量可能会被solve后使用
	char vis[maxn];	///visited（0未访问，壹在访问，2访问完）
	
	void init(int n) {
		this->n = n;
		memset(E, 255, sizeof(E));
		len = 0;
	}
	void addEdge(int a, int b) {
		buf[len].init(b, E[a]);		E[a] = len ++;
		buf[len].init(a, E[b]);		E[b] = len ++;
	}
	void dfs(int idx, int father, int deep) {
		static int D[maxn];		///某点的深度
		static int anc[maxn];	///祖先
		
		vis[idx] = 1;
		D[idx] = anc[idx] = deep;
		int tot = 0;
		for(int i = E[idx]; i != -1; i = buf[i].nxt) {
			int b = buf[i].b;
			if(vis[b]==1 && father!=b)
				anc[idx] = min(anc[idx], D[b]);
			if(vis[b] == 0) {
				dfs(b, idx, deep+1);
				tot ++;
				anc[idx] = min(anc[idx], anc[b]);
				if((deep==0&&tot>1) || (deep!=0 && anc[b]>=D[idx]))
					cut[idx] = true;
				if(anc[b]>D[idx])
					brg[i] = brg[i^1] = true;	//i^1 is the partner edge!
			}
		}
		vis[idx] = 2;
	}
	void floodFill(int idx) {//用id是否为-1，隐式表示有没有访问过
		id[idx] = nBcc;
		for(int i = E[idx]; i != -1; i = buf[i].nxt) {
			if(id[buf[i].b]==-1 && false==brg[i]) {
				floodFill(buf[i].b);
			}
		}
	}
	void solve() {
		memset(vis, 0, sizeof(vis));
		memset(cut, 0, sizeof(cut));
		memset(brg, 0, sizeof(brg));
		memset(id, 255, sizeof(id));
		memset(tot, 0, sizeof(tot));
		memset(EBcc, 255, sizeof(EBcc));
		nBcc = lenBcc = 0;
			//init over!
		for(int i=0; i<n; i++)	if(vis[i]==0)	dfs(i,i,0);
			///dfs结束，找出割点和桥
		for(int i=0; i<n; i++)	if(id[i]==-1)	floodFill(i), nBcc++;
			///找出双连通分支
		for(int i=0; i<n; i++)	tot[id[i]] ++;
			///统计出每个双连通分支包含点的个数
		for(int j = 0; j < n; j ++) {
			int a = id[j];
			for(int i = E[j]; i != -1; i = buf[i].nxt) {
				int b = id[buf[i].b];
				if(brg[i] && a<b) {
					bufBcc[lenBcc].init(b, EBcc[a]);	EBcc[a] = lenBcc ++;
					bufBcc[lenBcc].init(a, EBcc[b]);	EBcc[b] = lenBcc ++;
				}
			}
		}
			///所点后的图构建完毕，不含重边！
	}

} bcc;

