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
	int h, m, hh, mm;
	scanf("%d:%d\n", &h, &m);
	scanf("%d:%d\n", &hh, &mm);
	int ah, am;
	if (m >= mm) {
		am = m - mm;
	} else {
		am = m + 60 - mm;
		h--;
	}
	ah = h - hh;
	if (ah < 0) ah += 24;
	printf("%02d:%02d\n", ah, am);
	return 0;
}

