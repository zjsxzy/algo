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

const int MAXN = 1000000 + 5;
/*
 * One dimension Binary Index Tree. Notice that the array is C[1], C[2], ..., C[N]
 */
struct BinaryIndexTree {
	int N;
	int C[MAXN];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}
	
	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;

struct node {
	int val, pos, type;
	node() {}
	node(int val, int pos, int type) : val(val), pos(pos), type(type) {}
	bool operator < (const node &pt) const {
		return val == pt.val ? type > pt.type : val > pt.val;
	}
};
int n;
int a[MAXN], cnt[MAXN];

int main() {
	scanf("%d", &n);
	map<int, int> cnt;
	vector<node> vec;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		vec.PB(node(cnt[a[i]], i, 0));
	}
	cnt.clear();
	for (int i = n; i >= 1; i--) {
		cnt[a[i]]++;
		vec.PB(node(cnt[a[i]], i, 1));
	}
	
	bit.init(n);
	sort(vec.begin(), vec.end());
	LL ret = 0;
	for (int i = 0; i < vec.size(); i++) {
		node cur = vec[i];
		int j = cur.pos;
		if (cur.type == 0) {
			bit.add(j, 1);
		} else if (cur.type == 1 && j > 1) {
			ret += bit.sum(j - 1);
		}
	}
	cout << ret << endl;
	return 0;
}

