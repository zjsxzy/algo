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
struct BinaryIndexTree {
	int N;
	LL C[maxn];
	
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
	
	LL sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;
int n;
struct data {
	int val, idx, ori;
	bool operator < (const data &pt) const {
		return val < pt.val;
	}
};
bool cmp(const data &a, const data &b) {
	return a.ori < b.ori;
}
data p[maxn];
bool mk[maxn];
int pos[maxn];

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i].val);
			p[i].ori = i;
		}
		//question 1
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++)
			p[i].idx = i;
		sort(p + 1, p + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			pos[i] = p[i].idx;
		}
		LL cnt = 0;
		memset(mk, 0, sizeof(mk));
		for (int i = 1; i <= n; i++) {
			if (!mk[i]) {
				mk[i] = true;
				cnt++;
				for (int j = pos[i]; j != i; j = pos[j]) {
					mk[j] = true;
				}
			}
		}
		cout << n - cnt << endl;

		//question 2
		bit.init(n);
		LL reversion = 0;
		for (int i = n; i >= 1; i--) {
			LL sum = bit.sum(p[i].idx);
			reversion += sum;
			bit.add(p[i].idx, 1);
		}
		cout << reversion << endl;
	}
	return 0;
}
