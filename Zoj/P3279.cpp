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

const int maxn = 1000005;
struct BinaryIndexTree {
	int N;
	int C[maxn];
	
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
int n;
int a[maxn];

int main() {
	int n, q;
	while (~scanf("%d", &n)) {
		bit.init(n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			bit.add(i, a[i]);
		}
		scanf("%d", &q);
		while (q--) {
			char op[2];
			scanf("%s", op);
			if (*op == 'p') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				bit.add(pos, val - a[pos]);
				a[pos] = val;
			} else {
				int k;
				scanf("%d", &k);
				int lo = 1, hi = n, res = -1;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (bit.sum(mid - 1) < k) {	
						res = mid;
						lo = mid + 1;
					} else hi = mid - 1;
				}
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
