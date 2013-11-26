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

int main() {
	int n; 
	cin >> n;
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = min(a, b), y = min(c, d);
		if (x + y <= n) {
			cout << i + 1 << " " << x << " " << n - x << endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}

