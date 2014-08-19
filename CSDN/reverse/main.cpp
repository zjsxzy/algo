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

int reverse(int x) {
	vector<int> nx;
	bool pos = true;
	if (x < 0) {
		x = -x;
		pos = false;
	}
	while (x) {
		nx.PB(x % 10);
		x /= 10;
	}
	int ret = 0;
	for (int i = 0; i < nx.size(); i++)
		ret = ret * 10 + nx[i];
	return pos ? ret : -ret;
}

int main() {
	cout << reverse(123) << endl;
	cout << reverse(-123) << endl;
	return 0;
}

