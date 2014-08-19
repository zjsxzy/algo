#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define clr(a,b) memset(a,b,sizeof(a))

const int INF = 0x3f3f3f3f;
int n,m;
int dp[2][1<<7][1<<7];
char mark[10];
int cur,nex,flag,ss,fs;
int ans = INF;

int cc(int a, int b) { return a << b; }
bool exist(int s, int pos) { return s & cc(1,pos); }
void print(int x) {
    for(int i = 0; i < m; i ++) printf("%d", x>>i&1); puts("");
}

void dfs(int s, int ns, int pos, int val) {
 
    if(pos > 1 && exist(s,pos-2) && exist(s,pos-1)) return ;
    if(flag && pos > 1 && exist(ns,pos-2) && exist(ns,pos-1)) return ;
    if(flag && pos > 0 && exist(ns,pos-1) && exist(s,pos-1)) return ;
    if(pos == m) {
        if(flag) {
            ans = min(ans, val);
        } else {
            dp[nex][s][ns] = min(dp[nex][s][ns], val);
        }
        return ;
    }
    if(exist(fs,pos) && exist(s,pos)) {
        if(exist(ns,pos)) dfs(s^cc(1,pos), ns^cc(1,pos), pos+1, val+1);
    } else {
        if(exist(s,pos) && exist(ns,pos))  dfs(s^cc(1,pos), ns^cc(1,pos), pos+1, val+1);
        if(pos + 1 < m && exist(ns,pos) && exist(ns,pos+1)) dfs(s, ns^cc(3,pos), pos+1, val+1);
        dfs(s, ns, pos+1, val);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    clr(dp,INF);
    dp[0][0][0] = 0;
    cur = 0;
    nex = !cur;
    int all = cc(1,m) - 1;
    for(int i = 0; i < n; i ++) {
        scanf("%s", mark);
        if(i == n - 1) flag = 1;
        int ns = all;
        for(int j = 0; j < m; j ++) if(mark[j] == '*') ns ^= cc(1,j);
        for(int j = 0; j <= all; j ++) {
            int r;
            for(r = 1; r < m; r ++) if(exist(j,r) && exist(j,r-1)) break;
            if(r != m) continue;
            fs = j;
            for(int k = 0; k <= all; k ++) if(dp[cur][j][k] != INF) {
                ss = k;
                dfs(k,ns,0,dp[cur][j][k]);
            }
        }
        cur = nex, nex = !cur;
        clr(dp[nex],INF);
    }
    printf("%d\n", ans);
    return 0;
}
