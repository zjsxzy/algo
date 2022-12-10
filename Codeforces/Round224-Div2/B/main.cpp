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

LL a, b, w, x, c;

bool check(LL t) {
	LL final_c = c - t;
	LL delta = t * x;
	LL final_a = a - delta / w;
	delta %= w;
	if (delta > b) final_a--;
	return final_c <= final_a;
}

int main(int argc, char const *argv[])
{
	cin >> a >> b >> w >> x >> c;
	LL lo = 0, hi = 10000000000000l;
	LL ret = -1;
	while (lo <= hi) {
		LL mid = (lo + hi) >> 1l;
		if (check(mid)) {
			ret = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ret << endl;
	return 0;
}
