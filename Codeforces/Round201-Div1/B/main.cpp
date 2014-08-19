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
const int maxn = 1000;
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
			int t = *s - 'A';
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

int dp[105][105][105];
pair<pair<int, int>, int> pred[105][105][105];
string s1, s2;
char virus[105];

void update(int i, int j, int k, int u, int v, int w, int val) {
	if (dp[i][j][k] >= val) return;
	dp[i][j][k] = val;
	pred[i][j][k] = MP(MP(u, v), w);
}

void print(int i, int j, int k) {
	if (i == 0) return;	
	pair<pair<int, int>, int> temp = pred[i][j][k];
	print(temp.first.first, temp.first.second, temp.second);
	if (temp.first.first + 1 == i && temp.first.second + 1 == j) putchar(s1[temp.first.first]);
}

int main() {
	cin >> s1 >> s2;
	scanf("%s", virus);
	ac.init();
	ac.insert(virus, 1);
	ac.build();

	int res = -1;
	pair<pair<int, int>, int> out;
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			for (int cur = 0; cur <= ac.sz; cur++) {
				if (dp[i][j][cur] == -1) continue;
				int now = dp[i][j][cur];
				update(i + 1, j, cur, i, j, cur, now);
				update(i, j + 1, cur, i, j, cur, now);

				if (s1[i] == s2[j]) {
					int nxt = ac.tree[cur].son[s1[i] - 'A'];
					if (ac.tree[nxt].bad) continue;
					update(i + 1, j + 1, nxt, i, j, cur, now + 1);
					if (now >= res) {
						res = now + 1;
						out = MP(MP(i + 1, j + 1), nxt);
					}
				}
			}
		}
	}
	if (res == -1) {
		puts("0");
	} else {
		print(out.first.first, out.first.second, out.second);
		puts("");
	}
	return 0;
}
