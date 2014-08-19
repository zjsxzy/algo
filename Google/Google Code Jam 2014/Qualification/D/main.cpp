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

const int MAXN = 1000 + 5;
int n;
double Naomi[MAXN], Ken[MAXN];

int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		int DeceitfulWar = 0, War = 0;
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &Naomi[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", &Ken[i]);
		}
		sort(Naomi, Naomi + n);
		sort(Ken, Ken + n);

		// Calculate War Score
		set<double> st;
		set<double>::iterator it;
		for (int i = 0; i < n; i++) {
			st.insert(Ken[i]);
		}
		for (int i = 0; i < n; i++) {
			double x = Naomi[i];
			it = st.lower_bound(x);
			if (it == st.end()) {
				War++;
			} else {
				st.erase(it);
			}
		}

		// Calculate Deceitful War Score
		DeceitfulWar = 0;
		st.clear();
		for (int i = 0; i < n; i++) {
			st.insert(Ken[i]);
		}
		for (int i = n - 1; i >= 0; i--) {
			double x = Naomi[i];
			it = st.lower_bound(x);
			if (it != st.begin()) {
				DeceitfulWar++;
				it--;
				st.erase(it);
			}
		}
		printf("%d %d\n", DeceitfulWar, War);
	}
	return 0;
}

