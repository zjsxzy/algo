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

#define sqr(x) (x)*(x)
int main() {
	double X1, Y1, X2, Y2;
	scanf("%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
	printf("%.4f\n", sqrt(sqr(X1-X2) + sqr(Y1-Y2)));
	return 0;
}

