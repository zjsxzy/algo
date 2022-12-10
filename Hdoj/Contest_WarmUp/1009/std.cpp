#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 80

int N;
int F[MAXN+1][MAXN+1];
int C[MAXN+1][MAXN+1];
int SAVEF[MAXN+1][MAXN+1];

bool vis[MAXN+1][2];

/* Find an augmenting path through our compact graph representation. */
bool dfs(int x, bool s) {
  if(x == N && !s) return true;
  if(vis[x][s]) return false;
  vis[x][s] = true;

  for(int i = 0; i <= N; i++) {
    if(s ? F[i][x] : C[x][i] - F[x][i]) {
      if(dfs(i, !s)) {
        s ? --F[i][x] : ++F[x][i];
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char** argv) {
  for(cin >> N; ; cin >> N) {
    if(!N) break;
    memset(F, 0, sizeof(F));
    memset(C, 0, sizeof(C));

    /* Build the bipartite graph in a 'compact' representation. */
    for(int i = 0; i < N; i++) {
      string S; cin >> S;
      for(int j = 0; j < N; j++) {
        C[i][j] = S[j] == 'Y';
      }
    }

    /* Compute the maximum degree regular subgraph with max-flow. */
    int res;
    for(res = 0; ; res++) {
      /* Re-use the old flow so we only need to find N augmenting paths. */
      memcpy(SAVEF, F, sizeof(SAVEF));

      /* Add more capacity from the source and to the sink. */
      for(int j = 0; j < N; j++) {
        F[j][N]++; C[j][N]++;
        F[N][j]++; C[N][j]++;
      }

      /* Find N more augmenting paths. */
      bool ok = true;
      for(int j = 0; ok && j < N; j++) {
        memset(vis, 0, sizeof(vis));
        ok &= dfs(N, true);
      }

      /* We failed :( */
      if(!ok) {
        memcpy(F, SAVEF, sizeof(SAVEF));
        break;
      }
    }
    
    memcpy(C, F, sizeof(F));
    memset(F, 0, sizeof(F));

    /* Pull out perfect matchings from the maximum regular subgraph. */
    cout << res << endl;
    for(int i = 0; i < res; i++) {
      for(int i = 0; i < N; i++) {
        F[N][i] = C[N][i] = 1;
        F[i][N] = C[i][N] = 1;
      }
      for(int j = 0; j < N; j++) {
        memset(vis, 0, sizeof(vis));
        dfs(N, true);
      }

      for(int k = 0; k < N; k++) {
        for(int j = 0; j < N; j++) {
          if(F[j][k]) {
            if(k) cout << ' ';
            cout << j + 1;
            /* Remove this edge from the graph.  We end up reducing the degree
             * of our regular subgraph. */
            F[j][k] = C[j][k] = 0;
          }
        }
      }
      cout << endl;
    }
  }
}

