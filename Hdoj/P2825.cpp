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

const int mod = 20090717;
const int dict = 26;
const int root = 0;
const int maxn = 105;
struct AC{
	struct node {
		int son[dict], fail, idx, state;
	}tree[maxn];
	int sz;

	int initNode(int idx) {
		for (int i = 0; i < dict; i++) tree[idx].son[i] = 0;
		tree[idx].fail = tree[idx].idx = 0;
		tree[idx].state = 0;
		return idx;
	}
	void init() {
		sz = initNode(0);
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
		tree[cur].state |= 1 << idx;
	}
	//queue<int> q;
	int q[1000];
	void build() {
		//while (!q.empty()) q.pop();
		int head = 0, tail = 0;
		for (int i = 0; i < dict; i++)
			if (tree[root].son[i]) {
				//q.push(tree[root].son[i]);
				q[tail++] = tree[root].son[i];
			}
		while (head < tail) {
//		while (!q.empty()) {
//			int cur = q.front(); q.pop();
			int cur = q[head++];
			int f = tree[cur].fail;
			for (int i = 0; i < dict; i++) {
				if (tree[cur].son[i]) {
					int nxt = tree[cur].son[i];
					tree[nxt].fail = tree[f].son[i];
					tree[nxt].state |= tree[tree[nxt].fail].state;
					//q.push(nxt);
					q[tail++] = nxt;
				} else {
					tree[cur].son[i] = tree[f].son[i];
				}
			}
		}
	}

}ac;

int N, M, K;
int dp[2][105][1030];
void reset(int row) {
	for (int i = 0; i <= ac.sz; i++) {
		for (int j = 0; j < (1 << M); j++) {
			dp[row][i][j] = 0;
		}
	}
}
int main() {
	while (~scanf("%d%d%d", &N, &M, &K)) {
		if (N == 0 && M == 0 && K == 0) break;
		char str[15];
		ac.init();
		for (int i = 0; i < M; i++) {
			scanf("%s", str);
			ac.insert(str, i);
		}
		ac.build();

		int current = 0, pred = 1;
		reset(current);
		dp[current][0][0] = 1;
		for (int i = 0; i < N; i++) {
			current = pred; pred ^= 1;
			reset(current);
			for (int cur = 0; cur <= ac.sz; cur++) {
				for (int mask = 0; mask < (1 << M); mask++) {
					if (dp[pred][cur][mask] == 0) continue;
					for (int k = 0; k < dict; k++) {
						int nxt = ac.tree[cur].son[k];
						int newmask = mask | ac.tree[nxt].state;
						dp[current][nxt][newmask] += dp[pred][cur][mask];
						if (dp[current][nxt][newmask] >= mod) dp[current][nxt][newmask] -= mod;
					}
				}
			}
		}

		int res = 0;
		for (int cur = 0; cur <= ac.sz; cur++) {
			for (int mask = 0; mask < (1 << M); mask++) {
				int sum = 0;
				for (int temp = mask; temp; sum += (temp & 1), temp >>= 1);
				if (sum < K) continue;
				res += dp[current][cur][mask];
				if (res >= mod) res -= mod;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
