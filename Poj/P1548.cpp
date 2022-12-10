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
vector<pair<int, int> > p;


int main() {
	int x, y;
	while (~scanf("%d%d", &x, &y)) {
		if (x == -1 && y == -1) break;
		p.clear();
		p.PB(MP(x, y));
		while (scanf("%d%d", &x, &y)) {
			if (x + y == 0) break;
			p.PB(MP(x, y));
		}
		sort(p.begin(), p.end());
		vector<int> vec;
		for (int i = 0; i < SZ(p); i++) {
			int val = p[i].second;
			int lo = 0, hi = vec.size() - 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (vec[mid] > val) lo = mid + 1;
				else hi = mid - 1;
			}
			if (lo >= vec.size()) vec.PB(p[i].second);
			else vec[lo] = p[i].second;
		}
		cout << vec.size() << endl;
	}
	return 0;
}
