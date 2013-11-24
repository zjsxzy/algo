#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i, n) for(int i=0; i<n; i++)
#define FF(i, a, b) for(int i=a; i<b; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 100;
int n, m, T, g[maxn][maxn], dist[maxn][maxn];
bool vis[10000];
vector<pair<int, int> > edges;
vector<int> G[maxn];

bool gao(int x)
{
    FF(i, 1, n+1) FF(j, 1, n+1) if(i != j)
    {
        if(dist[i][j] == 0 && dist[j][i] == 0)
        {
            if(g[i][j] % 3 == x % 3)
            {
                dist[i][j] = x;
                return true;
            }
        }
    }
    return false;
}

bool solve()
{
    FF(i, 1, m+1) if(!vis[i])
        if(!gao(i)) return false;
    return true;
}

int dfs(int u, int pos, int fa, int len)
{
    if(u == pos) return len;
    REP(i, G[u].size())
    {
        int v = edges[G[u][i]].first, w = edges[G[u][i]].second;
        if(v != fa) return dfs(v, pos, u, len+w);
    }
}

void build()
{
    CLR(vis, 0); CLR(dist, 0);
    REP(i, n+1) G[i].clear();   edges.clear();
    int tot = 0, sz = 0;
    FF(i, 1, n)
    {
        edges.push_back(make_pair(i+1, i));
        G[i].push_back(sz++);
        vis[i] = 1; dist[i][i+1] = i;
        tot += i;
    }
    FF(i, n, n+3) if((tot + i) % 3 == 0)
    {
        edges.push_back(make_pair(1, i));
        G[n].push_back(sz);
        vis[i] = 1; dist[n][1] = i;
        break;
    }
    FF(i, 1, n+1) FF(j, 1, n+1)
        g[i][j] = dfs(i, j, -1, 0);
}

int main()
{
    scanf("%d", &T);
    FF(kase, 1, T+1)
    {
        scanf("%d%d", &n, &m);
        build();
        printf("Case #%d:n", kase);
        if(solve())
        {
            FF(i, 1, n+1) FF(j, 1, n+1) if(dist[i][j])
                printf("%d %d %d\n", i, j, dist[i][j]);
        }
        else puts("-1");
    }
    return 0;
}
