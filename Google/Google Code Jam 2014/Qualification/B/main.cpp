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

int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double ret = 0, sum = 0, rate = 2;
		while (C / rate + X / (rate + F) < X / rate) {
			ret += C / rate;
			rate += F;
		}
		ret += X / rate;
		printf("%.7f\n", ret);
	}
	return 0;
}

