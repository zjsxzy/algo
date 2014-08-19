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

const int maxn = 100000 + 5;
struct Trie {
	int n;
	pair<int, int> node[32 * maxn];
	vector<int> toVec(int v) {
		vector<int> vec;
		for (; v; v >>= 1) {
			vec.PB(v & 1);
		}
		while (vec.size() < 32) vec.PB(0);
		return vec;
	}
	void initNode() {
		node[n].first = node[n].second = -1;
		n++;
	}
	void init() {
		n = 0;
		initNode();
	}
	void insert(int v) {
		vector<int> vec = toVec(v);
		int cur = 0;
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (vec[i] == 0) {
				if (node[cur].first == -1) {
					node[cur].first = n;
					initNode();
				}
				cur = node[cur].first;
			} else {
				if (node[cur].second == -1) {
					node[cur].second = n;
					initNode();
				}
				cur = node[cur].second;
			}
		}
	}
	int query(int v) {
		vector<int> vec = toVec(v);
		int cur = 0, res = 0;
		for (int i = vec.size() - 1; i >= 0; i--) {
			res <<= 1;
			if (vec[i] == 0) {
				if (node[cur].second == -1) {
					cur = node[cur].first;
				} else {
					cur = node[cur].second;
					res++;
				}
			} else {
				if (node[cur].first == -1) {
					cur = node[cur].second;
					res++;
				} else {
					cur = node[cur].first;
				}
			}
		}
		return res;
	}
}tree;

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		int n;
		scanf("%d", &n);
		int res = 0;
		int xorPrefix = 0;
		tree.init();
		tree.insert(0);
		for (int i = 1; i <= n; i++) {
			int a; scanf("%d", &a);
			xorPrefix ^= a;
			int temp = tree.query(xorPrefix) ^ xorPrefix;
			res = max(res, temp);
			tree.insert(xorPrefix);
		}
		printf("%d\n", res);
	}
	return 0;
}

