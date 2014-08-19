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
int n, k;
int card[MAXN], pos[MAXN];
bool Remove[MAXN];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		pos[card[i]] = i;
	}
	memset(Remove, 0, sizeof(Remove));
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		Remove[x] = true;
	}
	bit.init(n + 1);
	LL ret = 0;
	set<int> occ;
	occ.insert(0); occ.insert(n + 1);
	for (int i = 1; i <= n; i++) {
		int p = pos[i];
		if (Remove[i]) {
			occ.insert(p);
		} else {
			int ll = *--occ.lower_bound(p), rr = *occ.upper_bound(p);
			//int add = rr - ll - 1 - (bit.sum(rr) - bit.sum(ll));
			int add = rr - ll - 1 - (bit.sum(rr) - (ll > 1 ? bit.sum(ll - 1) : 0));
			//cout << i << " " << ll << " " << rr << " " << add << endl;
			ret += (LL)add;
			bit.add(p, 1);
		}
	}
	cout << ret << endl;
	return 0;
}

