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

const int maxn = 10000 + 5;
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
const double eps = 1e-6;
int sig(double d) {
	return (d > eps) - (d < -eps);
}
struct line {
	double k, b;
	double l, r;
	int idxr;
	line() {}
	line(double k, double b) : k(k), b(b) {}
	bool operator < (const line &pt) const {
		return l > pt.l;
	}
};
int n;
double L, R;
vector<line> vec;

bool cmp(const line &a, const line &b) {
	return a.r < b.r;
}

int main() {
	while (~scanf("%d", &n)) {
		vec.clear();
		for (int i = 0; i < n; i++) {
			double X1, X2, Y1, Y2;
			scanf("%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
			double k = (Y1 - Y2) / (X1 - X2);
			double b = Y1 - k * X1;
			vec.PB(line(k, b));
		}
		scanf("%lf%lf", &L, &R);
		L += eps; R -= eps;
		for (int i = 0; i < n; i++) {
			vec[i].l = vec[i].k * L + vec[i].b;
			vec[i].r = vec[i].k * R + vec[i].b;
		}
		sort(vec.begin(), vec.end(), cmp);
		for (int i = 0; i < n; i++) {
			vec[i].idxr = i + 1;
		}
		sort(vec.begin(), vec.end());
		bit.init(n);
		LL res = 0;
		for (int i = 0; i < n; i++) {
			res += bit.sum(vec[i].idxr);
			bit.add(vec[i].idxr, 1);
		}
		
		cout << res << endl;
	}
	return 0;
}
