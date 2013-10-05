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

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);	
	}
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	n = x.size();
	int a, b;
	cin >> a >> b;
	int res = 0;
	while (a != b) {
		int a1 = a - 1;
		for (int i = x.size() - 1; i >= 0 && x[i] > a - a1; i--) {
			int cur = a - a % x[i];
			if (cur >= b && cur < a1) {
				a1 = cur;
			}
		}
		while (!x.empty() && a - a % x.back() < b) {
			x.pop_back();
		}
		swap(a1, a);
		res++;
	}
	cout << res << endl;
	return 0;
}
