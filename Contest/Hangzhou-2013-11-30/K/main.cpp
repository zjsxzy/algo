#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

#define maxV 450
#define maxE 100 * maxV
const int inf = 0x3f3f3f3f;
struct Nod {
    int b, nxt;
    int cap, cst;
    void init(int b, int nxt, int cap,int cst) {
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
    void addCap(int a, int b, int cap, int cst) {
		//cout << a << " -> " << b << " " << cap << " " << cst << endl;
        buf[len].init(b, E[a], cap, cst);   E[a] = len ++;
        buf[len].init(a, E[b], 0,  -cst);   E[b] = len ++;
    }
    bool spfa(int source, int sink) {
        static queue<int> q;
        static int d[maxV];
        memset(d,  63, sizeof(d));
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
    pair<int, int> solve(int source, int sink) {
        int minCost = 0,maxFlow = 0;
        while(spfa(source, sink)) {
            int neck = inf;
            for(int t=p[sink]; t != -1; t = p[ buf[t^1].b ])
                neck = min(neck, buf[t].cap);
            maxFlow += neck;
            for(int t = p[sink]; t != -1; t = p[ buf[t^1].b ]) {
                buf[t].cap -= neck;
                buf[t^1].cap += neck;
                minCost += buf[t].cst * neck;
            }
        }
        return MP(maxFlow, minCost);
    }
} mcmf;

const int maxn = 300 + 5;
int n, m, K;
int s[maxn], t[maxn];
int C[maxn][maxn], D[maxn][maxn], E[maxn][maxn], F[maxn][maxn];

int main() {
	while (~scanf("%d%d%d", &n, &m, &K)) {
		if (n == 0 && m == 0 && K == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", s + i, t + i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &C[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &D[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &E[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &F[i][j]);
			}
		}

		int source = 0, sink = m + n + n + n + 1;
		mcmf.init(m + n + n + n + 2);
		for (int i = 1; i <= n; i++) {
			mcmf.addCap(source, i, 1, 0);
			mcmf.addCap(i, n + i, 1, 0);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (C[i][j] >= t[i]) continue;
				int cst = D[i][j] + K * max(0, C[i][j] - s[i]);
				mcmf.addCap(n + i, n + n + n + j, 1, cst);
			}
		}
		for (int i1 = 1; i1 <= n; i1++) {
			for (int i2 = 1; i2 <= n; i2++) {
				if (E[i1][i2] == -1) continue;
				if (t[i1] + E[i1][i2] >= t[i2]) continue;
				int cst = F[i1][i2] + K * max(0, t[i1] + E[i1][i2] - s[i2]);
				mcmf.addCap(n + i2, n + n + i1, 1, cst);
			}
		}
		for (int i = 1; i <= n; i++) {
			mcmf.addCap(n + n + i, sink, 1, 0);
		}
		for (int j = 1; j <= m; j++) {
			mcmf.addCap(n + n + n + j, sink, 1, 0);
		}
		pair<int, int> ret = mcmf.solve(source, sink);
		printf("%d\n", ret.first < n ? -1 : ret.second);
	}
	return 0;
}

