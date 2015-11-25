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

const int MAXN = 1000 + 5;
LL N, M, A, B;
LL ax[MAXN], ay[MAXN], bx[MAXN], by[MAXN];
LL func(LL x, LL y, LL sumx, LL sumy, LL sumSqx, LL sumSqy, LL xk, LL yk) {
	return x * x * A - 2 * sumx * x + sumSqx + y * y * A - 2 * sumy * y + sumSqy + abs(x - xk) + abs(y - yk);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		cin >> N >> M >> A >> B;
		LL sumx = 0, sumy = 0, sumSqx = 0, sumSqy = 0;
		for (int i = 0; i < A; i++) {
			cin >> ax[i] >> ay[i];
			sumx += ax[i];
			sumSqx += ax[i] * ax[i];
			sumy += ay[i];
			sumSqy += ay[i] * ay[i];
		}
		LL ret = 1LL << 60;
		// cout << sumx << " " << sumy << " " << sumSqx << " " << sumSqy << endl;
		for (int i = 0; i < B; i++) {
			cin >> bx[i] >> by[i];
			LL lx = sumx * 2 / (2 * A - 1), rx = sumx * 2 / (2 * A + 1) + 1;
			LL ly = sumy * 2 / (2 * A - 1), ry = sumy * 2 / (2 * A + 1) + 1;
			for (LL x = lx; x <= rx; x++) {
				for (LL y = ly; y <= ry; y++) {
					LL temp = func(x, y, sumx, sumy, sumSqx, sumSqy, bx[i], by[i]);
					if (temp < ret) {
						ret = temp;
					}
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}

