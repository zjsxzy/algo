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
#include <cassert>
#include <climits>
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

const int MAXN = 1000 + 5;
int mk[MAXN], mate[MAXN];
vector<int> adj[MAXN];
int n;
int num[MAXN];
set<int> prime;
int vst[555555];
void addEdge(int u, int v) {
	adj[u].PB(v);
	// cout << u << "->" << v << endl;
}

int path(int u) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if (!mk[v = adj[u][i]]) {
			mk[v] = 1;
			if (mate[v] == -1 || path(mate[v])) {
				mate[u] = v;
				mate[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int MaxMatch() {
	memset(mate, -1, sizeof(mate));
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (mate[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}


void getPrime() {
	memset(vst, false, sizeof(vst));
	for (int i = 2; i <= 500000; i++) {
		if (!vst[i]) {
			prime.insert(i);
			for (int j = 2; i * j <= 500000; j++) {
				vst[i * j] = true;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	getPrime();
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", num + i);
			adj[i].clear();
		}
		
		sort(num, num + n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (num[j] % num[i] == 0) {
					if (prime.find(num[j] / num[i]) != prime.end()) {
						addEdge(i, j);
						addEdge(j, i);
					}
				}
			}
		}
		int sum = MaxMatch();
		printf("Case #%d: %d\n", cas, n - sum);
	}
	return 0;
}

