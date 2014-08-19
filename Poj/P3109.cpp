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

const int MAXN = 100000 + 5;
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

void compress(int as[], int n, int &L) {
	vector<int> num;
	for (int i = 0; i < n; i++) {
		num.PB(as[i]);
	}
	sort(num.begin(), num.end());
	L = unique(num.begin(), num.end()) - num.begin();
	for (int i = 0; i < n; i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}

int n, nx, ny;
int xs[MAXN], ys[MAXN];
int ll[MAXN], rr[MAXN];
pair<int, int> ps[MAXN];

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", xs + i, ys + i);
		}
		compress(xs, n, nx);
		compress(ys, n, ny);
		
		for (int i = 1; i <= n; i++) {
			ll[i] = n + 1;
			rr[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			ps[i] = MP(xs[i], ys[i]);
			ll[ys[i]] = min(ll[ys[i]], xs[i]);
			rr[ys[i]] = max(rr[ys[i]], xs[i]);
		}
		
		sort(ps, ps + n);
		LL res = 0;
		bit.init(n);
		for (int i = 0; i < n; ) {
			int j = i;
			for (; ps[i].first == ps[j].first && j < n; j++);
			for (int k = i; k < j; k++) {
				if (ll[ps[k].second] == ps[k].first) {
					bit.add(ps[k].second, 1);
				}
			}
			LL temp = bit.sum(ps[j - 1].second) - bit.sum(ps[i].second - 1);
			res += temp;
			for (int k = i; k < j; k++) {
				if (rr[ps[k].second] == ps[k].first) {
					bit.add(ps[k].second, -1);
				}
			}
			i = j;
		}
		cout << res << endl;
	}
	return 0;
}
