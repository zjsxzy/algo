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

const int maxn = 1005;
struct BinaryIndexTree {
	int N;
	int C[maxn][maxn];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int y, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			for (int j = y; j <= N; j += lowbit(j))
				C[i] += num;
	}
	
	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}T;

int main() {
	int n, m;
	kk
}
