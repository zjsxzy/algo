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

LL L, D, S, C;

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> L >> D >> S >> C;
		LL i, ret = S;
		for (i = 2; ret < L && i <= D; i++) {
			ret *= (C + 1);
		}
		if (ret >= L) {
			puts("ALIVE AND KICKING");
		} else {
			puts("DEAD AND ROTTING");
		}
	}
	return 0;
}

