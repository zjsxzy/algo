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

void work(LL &res, vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		res += (LL)(i) * vec[i] - (LL)(vec.size() - i) * vec[i];
	}
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		vector<int> ab(n), bc(n), ca(n);
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ab[i] = a - b; bc[i] = b - c; ca[i] = c - a;
		}

		sort(ab.begin(), ab.end());
		sort(bc.begin(), bc.end());
		sort(ca.begin(), ca.end());

		LL res = 0;
		work(res, ab);
		work(res, bc);
		work(res, ca);
		
		cout << res / 2 << endl;
	}
	return 0;
}
