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

const int maxn = 16000 + 5;
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
struct node {
	int a, b, ida;
	bool operator < (const node &pt) const {
		return b > pt.b;
	}
}p[maxn];
int n;

int main() {
	scanf("%d", &n);
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].a, &p[i].b);
		num[i] = p[i].a;
	}
	sort(num.begin(), num.end());
	unique(num.begin(), num.end());
	for (int i = 0; i < n; i++) {
		p[i].ida = lower_bound(num.begin(), num.end(), p[i].a) - num.begin() + 1;
	}
	sort(p, p + n);
	int ret = 0;
	bit.init(n);
	for (int i = 0; i < n; i++) {
		int temp = bit.sum(p[i].ida);
		if (temp > 0) {
			//cout << p[i].a << " " << p[i].b << endl;
			ret++;
		}
		bit.add(p[i].ida, 1);
	}
	printf("%d\n", ret);
	return 0;
}
