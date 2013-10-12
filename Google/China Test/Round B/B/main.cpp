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

const int maxn = 1000005;
int n;
vector<pair<int, int> > ps;
vector<int> vx, vy; 
LL sumx[maxn], sumy[maxn];

int main() {
	int Test;
	cin >> Test;
	for (int cas = 1; cas <= Test; cas++) {
		ps.clear();
		vx.clear();
		vy.clear();
		sumx[0] = 0;
		sumy[0] = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int xl, xr, yl, yr;
			cin >> xl >> yl >> xr >> yr;
			for (int x = xl; x <= xr; x++) {
				for (int y = yl; y <= yr; y++) {
					ps.PB(MP(x, y));
					vx.PB(x); vy.PB(y);
				}
			}
		}
		n = ps.size();
		sort(ps.begin(), ps.end());
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		for (int i = 0; i < n; i++) {
			sumx[i + 1] = sumx[i] + vx[i];
			sumy[i + 1] = sumy[i] + vy[i];
		}

		pair<int, int> pos;
		LL res = 1LL << 60;
		for (int i = 0; i < n; i++) {
			pair<int, int> cur = ps[i];
			int tx = lower_bound(vx.begin(), vx.end(), cur.first) - vx.begin();
			int ty = lower_bound(vy.begin(), vy.end(), cur.second) - vy.begin();
			LL calcx = (LL)cur.first * (tx + 1) - sumx[tx + 1] + sumx[n] - sumx[tx + 1] - (LL)cur.first * (n - tx - 1);
			LL calcy = (LL)cur.second * (ty + 1) - sumy[ty + 1] + sumy[n] - sumy[ty + 1] - (LL)cur.second * (n - ty - 1);
			if (calcx + calcy < res) {
				res = calcx + calcy;
				pos = ps[i];
			}
		}
		printf("Case #%d:", cas);
		cout << " " << pos.first << " " << pos.second << " " << res << endl;
	}
	return 0;
}
