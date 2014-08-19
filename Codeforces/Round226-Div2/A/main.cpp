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

const int MAXN = 100 + 5;
int n, c;
int p[MAXN];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int ret = 0;
	for (int i = 1; i < n; i++) {
		ret = max(ret, p[i - 1] - p[i] - c);
	}
	cout << ret << endl;
	return 0;
}

