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

const int MAXN = 500 + 5;
struct Rect {
	int w, h;
	Rect() {}
	Rect(int _w, int _h) {
		w = _w;
		h = _h;
		if (w > h) swap(w, h);
	}
	bool operator < (const Rect &pt) const {
		return w == pt.w ? h < pt.h : w < pt.w;
	}
};
int n, m;
vector<int> a;
int solve() {
	scanf("%d%d", &n, &m);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = 1 << a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int ret = 0;
	multiset<Rect> st;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		FOREACH(it, st) {
			if (it->w >= a[i]) {
				//cout << it->w << " " << it->h << endl;
				flag = true;
				if ((it->w > a[i]) && (it->h > a[i])) {
					st.insert(Rect(it->w - a[i], it->h - a[i]));
				}
				if (it->w > a[i]) {
					st.insert(Rect(it->w - a[i], a[i]));
				}
				if (it->h > a[i]) {
					st.insert(Rect(it->h - a[i], a[i]));
				}
				st.erase(it);
				break;
			}
		}
		if (!flag) {
			ret++;
			if (m - a[i]) {
				st.insert(Rect(m - a[i], m - a[i]));
				st.insert(Rect(m - a[i], a[i]));
				st.insert(Rect(a[i], m - a[i]));
			}
		}
	}
	return ret;
}
int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: %d\n", cas, solve());
	}
	return 0;
}

