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

const int mod = 10007;
const int dict = 4;
const int root = 0;
const int maxn = 10000;
int mp[512];
void pre() {
	mp['A'] = 0; mp['T'] = 1; mp['C'] = 2; mp['G'] = 3;
}
struct AC{
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
		while (*s) {
			int t = mp[*s];
			if (!tree[cur].son[t]) {
				tree[cur].son[t] = initNode(++sz);
			}
			cur = tree[cur].son[t];
			s++;
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


struct Matrix {
	int n, m;
	int mat[100][100];

	void init() {
		n = m = 0;
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator + (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] + b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator - (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] - b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator * (const Matrix &b) const {
		Matrix tmp;
		tmp.init();
		tmp.n = n; tmp.m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k] * b.mat[k][j]) % mod;
				}
			}
		}
		return tmp;
	}
	Matrix operator ^ (int x) {
		Matrix res, p = *this;
		res.init();
		res.n = res.m = n;
		for (int i = 0; i < n; i++)
			res.mat[i][i] = 1;
		for (; x; x >>= 1) {
			if (x & 1) res = res * p;
			p = p * p;
		}
		return res;
	}
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int n, l;

int quick_pow(int m, int x) {
	int res = 1;
	for (; x; x >>= 1) {
		if (x & 1) res = res * m % mod;
		m = m * m % mod;
	}
	return res;
}

void work() {
	Matrix F;
	F.init();
	F.n = F.m = 2 * ac.sz;
	for (int i = 0; i < ac.sz; i++) {
		for (int k = 0; k < 4; k++) {
			int j = ac.tree[i].son[k];
			if (ac.tree[j].bad) {
				F.mat[i][j + ac.sz]++;
			} else {
				F.mat[i][j]++;
				F.mat[i + ac.sz][j + ac.sz]++;
			}
		}
	}
	F = F ^ l;
	int res = quick_pow(4, l);
	for (int i = 0; i < ac.sz * 2; i++) {
		res = (res - F.mat[0][i] + mod) % mod;
	}
	res = (res + mod) % mod;
	printf("%d\n", res);
}

int main() {
	pre();
	char str[100];
	while (~scanf("%d%d", &n, &l)) {
		ac.init();
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			ac.insert(str, i);
		}
		ac.build();
		ac.sz++;
		work();
	}
	return 0;
}
