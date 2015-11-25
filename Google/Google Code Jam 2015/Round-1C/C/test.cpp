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
#include <cassert>
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

int C, D, V;
set<int> st;
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> C >> D >> V;
		st.clear();
		for (int i = 0; i < D; i++) {
			int x;
			cin >> x;
			st.insert(x);	
		}
		int res = 0;
		for (int i = 1; i <= 5; i++) {
			if (st.find(i) == st.end()) {
				res++;
			}
			if ((1 << i) >= V) break;
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}

