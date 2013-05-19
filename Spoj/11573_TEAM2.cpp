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

int main(int argc, char const *argv[])
{
	int a[5];
	int cas = 1;
	while (~scanf("%d%d%d%d", a+0, a+1, a+2, a+3)) {
		sort(a, a + 4);
		printf("Case %d: %d\n", cas++, a[2] + a[3]);
	}
	return 0;
}