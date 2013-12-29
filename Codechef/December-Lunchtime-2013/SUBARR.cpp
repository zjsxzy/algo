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
int n;
LL K;
LL sum[MAXN], as[MAXN];

void compress() {
	vector<LL> num;
	for (int i = 0; i <= n; i++) {
		num.PB(as[i]);
	}
	sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i <= n; i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}

int main() {
	while (cin >> n >> K) {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		for (int i = 0; i <= n; i++) {
			as[i] = sum[i] - K * i;
		}
		compress();

		LL ret = 0;
		bit.init(n + 1);
		for (int i = 0; i <= n; i++) {
			ret += bit.sum(as[i]);
			bit.add(as[i], 1);
		}
		cout << ret << endl;
	}
	return 0;
}

