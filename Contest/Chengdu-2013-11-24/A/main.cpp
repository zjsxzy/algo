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

const int maxn = 80 + 5;
int n, m;
int adj[maxn][maxn], dist[maxn][maxn];

int main() {
	int ts;
	scanf("%d", &ts);
	int cas = 1;
	while (ts--) {
		scanf("%d%d", &n, &m);
		printf("Case #%d:\n", cas++);
		set<int> ed;
		for (int i = 1; i <= m; i++)
			ed.insert(i);
		memset(adj, 0, sizeof(adj));
		memset(dist, 0, sizeof(dist));
		int sum = 0;
		for (int i = 1; i < n; i++) {
			adj[i][i + 1] = i;
			sum += i;
			ed.erase(i);
		}
		if ((sum + n) % 3 == 0) {
			adj[n][1] = n;
			ed.erase(n);
		} else if ((sum + n + 1) % 3 == 0) {
			adj[n][1] = n + 1;
			ed.erase(n + 1);
		} else if ((sum + n + 2) % 3 == 0) {
			adj[n][1] = n + 2;
			ed.erase(n + 2);
		}

		for (int i = 1; i <= n; i++) {
			int j = i + 1 == n + 1 ? 1 : i + 1;
			int sum = 0;
			for (; i != j;) {
				sum += adj[j - 1 == 0 ? n : j - 1][j];
				dist[i][j] = sum;
				if (j == n) j = 1;
				else j++;
			}
		}

		bool possible = true;
		while (ed.size()) {
			set<int>::iterator it = ed.begin();
			int w = *it;
			bool flag = true;
			for (int i = 1; i <= n && flag; i++)
				for (int j = 1; j <= n && flag; j++) {
					if (i == j) continue;
					if (adj[i][j] != 0 || adj[j][i] != 0) continue;
					if ((dist[i][j] + w) % 3 == 0) {
						adj[j][i] = w;
						ed.erase(w);
						flag = false;
					}
				}
			if (flag) {
				possible = false;
				break;
			}
		}
		if (!possible) {
			puts("-1");
		} else {
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (adj[i][j])
						printf("%d %d %d\n", i, j, adj[i][j]);
		}
	}
	return 0;
}

