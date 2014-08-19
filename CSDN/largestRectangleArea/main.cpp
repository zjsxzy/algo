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

int largestRectangleArea(vector<int> &height) {
	int n = height.size();
	vector<int> ll(n), rr(n);
	for (int i = 0; i < n; i++) {
		ll[i] = i;
		while (ll[i] > 0 && height[i] <= height[ll[i] - 1]) {
			ll[i] = ll[ll[i] - 1];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		rr[i] = i;
		while (rr[i] < n - 1 && height[i] <= height[rr[i] + 1]) {
			rr[i] = rr[rr[i] + 1];
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, height[i] * (rr[i] - ll[i] + 1));
	}
	return ret;
}

int main() {
	int a[] = {2, 1, 5, 6, 2, 3};
	vector<int> h(a, a + 6);
	cout << largestRectangleArea(h) << endl;
	return 0;
}
