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

const int dict = 26;
const int root = 0;
const int maxn = 3000000;
struct AC{
	struct node {
		int son[dict], fail, idx;
	}tree[maxn];
	bool vis[maxn];
	bool apr[10010];
	int cnt[10010];
	int sz;

	int initNode(int idx) {
		memset(tree[idx].son, 0, sizeof(tree[idx]));
		tree[idx].fail = tree[idx].idx = 0;
		return idx;
	}
	void init() {
		sz = initNode(0);
		memset(apr, 0, sizeof(apr));
		memset(cnt, 0, sizeof(cnt));
	}
	void insert(char *s, int idx) {
		int cur = root;
		while (*s) {
			int t = *s - 'a';
			if (!tree[cur].son[t]) {
				tree[cur].son[t] = initNode(++sz);
			}
			cur = tree[cur].son[t];
			s++;
		}
		if (tree[cur].idx != 0) cnt[tree[cur].idx]++;
		else tree[cur].idx = idx;
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
					q.push(nxt);
				} else {
					tree[cur].son[i] = tree[f].son[i];
				}
			}
		}
	}

	int match(char *s) {
		for (int i = 0; i <= sz; i++)
			vis[i] = 0;
		int cur = 0;
		for (; *s; s++) {
			cur = tree[cur].son[*s - 'a'];
			for (int i = cur; i && !vis[i]; i = tree[i].fail) {
				vis[i] = 1;
				apr[tree[i].idx] = 1;
			}
		}
		int ret = 0;
		for (int i = 1; i <= 10010; i++) {
			if (apr[i]) {
				ret++;
				ret += cnt[i];
			}
		}
		return ret;
	}
}ac;

char str[1000010];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		ac.init();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			ac.insert(str, i);
		}
		ac.build();
		scanf("%s", str);
		printf("%d\n", ac.match(str));
	}
	return 0;
}
