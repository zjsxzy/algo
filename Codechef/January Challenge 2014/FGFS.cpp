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

int n, K;
map<int, vector<pair<int, int> > > mp;

int solve(vector<pair<int, int> > vec) {
	sort(vec.begin(), vec.end());
	int cur = vec[0].first, ret = 1;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].second >= cur) {
			ret++;
			cur = vec[i].first;
		}
	}
	return ret;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		mp.clear();
		scanf("%d%d", &n, &K);
		for (int i = 0; i < n; i++) {
			int s, f, p;
			scanf("%d%d%d", &s, &f, &p);
			mp[p].push_back(make_pair(f, s));
		}
		int ret = 0;
		FOREACH(it, mp) {
			ret += solve(it->second);
		}
		printf("%d\n", ret);
	}
	return 0;
}

