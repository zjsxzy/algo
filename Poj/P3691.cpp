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

const int dict = 4;
const int root = 0;
const int maxn = 1000;
int mp[512];
void pre() {
	mp['A'] = 0; mp['C'] = 1; mp['T'] = 2; mp['G'] = 3;
}
struct AC {
	struct node {
		int son[dict], fail, idx, bad;
	}tree[maxn];
	int sz;

	int initNode(int idx) {
		memset(tree[idx].son, 0, sizeof(tree[idx]));
		tree[idx].fail = tree[idx].idx = 0;
		tree[idx].bad = 0;
		return idx;
	}
	void init() {
		sz = initNode(0);
	}
	void insert(char *s, int idx) {
		int cur = root;
		for (; *s; s++) {
			int t = mp[*s];
			if (!tree[cur].son[t]) {
				tree[cur].son[t] = initNode(++sz);
			}
			cur = tree[cur].son[t];
		}
		tree[cur].bad = true;
	}
	queue<int> q;
	void build() {
		while (!q.empty()) q.pop();
		for (int i = 0; i < dict; i++)
			if (tree[root].son[i]) {
				q.push(tree[root].son[i]);
			}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int f = tree[cur].fail;
			for (int i = 0; i < dict; i++) {
				if (tree[cur].son[i]) {
					int nxt = tree[cur].son[i];
					tree[nxt].fail = tree[f].son[i];
					tree[nxt].bad |= tree[tree[nxt].fail].bad;
					q.push(nxt);
				} else {
					tree[cur].son[i] = tree[f].son[i];
				}
			}
		}
	}
}ac;

const int inf = 10000000;
int n;
int dp[maxn][maxn];
int main() {
	int cas = 1;
	char str[100];
	char st[1005];
	pre();
	while (~scanf("%d", &n) && n) {
		ac.init();
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			ac.insert(str, i);
		}
		ac.build();
		scanf("%s", st);
		int len = strlen(st);
		for (int i = 0; i <= len; i++) {
			for (int j = 0; j <= ac.sz; j++) {
				dp[i][j] = inf;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < len; i++) {
			for (int cur = 0; cur <= ac.sz; cur++) {
				for (int k = 0; k < dict; k++) {
					int nxt = ac.tree[cur].son[k];
					if (ac.tree[nxt].bad) continue;
					int temp = mp[st[i]] == k ? 0 : 1;
					if (dp[i][cur] + temp < dp[i + 1][nxt]) {
						dp[i + 1][nxt] = dp[i][cur] + temp;
					}
				}
			}
		}

		int res = inf;
		for (int i = 0; i <= ac.sz; i++)
			if (dp[len][i] < res) {
				res = dp[len][i];
			}
		printf("Case %d: %d\n", cas++, res == inf ? -1 : res);
	}
	return 0;
}
