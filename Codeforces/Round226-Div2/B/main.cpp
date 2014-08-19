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

string str;
int main() {
	cin >> str;
	int last = -1, ret = 0, n = str.size();
	for (int i = 0; i + 3 < n; i++) {
		if (str.substr(i, 4) == "bear") {
			ret += (i - last) * (n - i - 3);
			last = i;
		}
	}
	cout << ret << endl;
	return 0;
}

