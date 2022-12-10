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

const int maxn = 50000 + 5;
int n;
int edges, verts;
vector<int> adj[maxn];
int rate[maxn];
int component[maxn];

void dfs(int u, int comp_id) {
	if (component[u]) return;
	component[u] = comp_id;
	verts++;
	for (int i = 0; i < adj[u].size(); i++) {
		dfs(adj[u][i], comp_id);
		edges++;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (; tc--; ) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			component[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--; b--;
			adj[a].PB(b); adj[b].PB(a);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &rate[i]);
		}

		vector<int> trees;
		int n_comp = 0;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (!component[i]) {
				edges = 0, verts = 0;
				n_comp++;
				dfs(i, n_comp);

				edges /= 2;
				if (edges > verts) {
					possible = false;
					break;
				} else if (edges == verts) {
					
				} else {
					trees.PB(n_comp);
				}
			}
		}
		if (!possible || trees.size() > 1) {
			puts("impossible");
			continue;
		}

		int Best = 0, secBest = 0;
		int Best_id = n, secBest_id = n;
		for (int i = 0; i < n; i++) {
			if (component[i] != trees[0]) continue;
			if (Best < rate[i]) {
				secBest = Best; secBest_id = Best_id;
				Best = rate[i]; Best_id = i;
			} else if (secBest < rate[i]) {
				secBest = rate[i]; secBest_id = i;
			}
		}

		if (n_comp > 1) {
			for (int i = 0; i < n; i++) {
				if (component[i] != trees[0] && (secBest < Best || (secBest == Best && i < secBest_id))) {
					secBest = rate[i];
					secBest_id = i;
					break;
				}
			}
		}
		if (Best_id > secBest_id) swap(Best_id, secBest_id);
		printf("%d %d\n", Best_id + 1, secBest_id + 1);
	}
	return 0;
}
