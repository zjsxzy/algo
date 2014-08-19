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

const int n = 4;
int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		int row;
		scanf("%d", &row);
		row--;
		set<int> st;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				if (i == row) st.insert(x);
			}
		}
		int cnt = 0;
		scanf("%d", &row);
		row--;
		int ret = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				if (i == row) {
					if (st.find(x) != st.end()) {
						cnt++;
						ret = x;
					}
				}
			}
		}
		if (cnt == 1) {
			printf("%d\n", ret);
		} else if (cnt == 0) {
			puts("Volunteer cheated!");
		} else {
			puts("Bad magician!");
		}
	}
	return 0;
}

