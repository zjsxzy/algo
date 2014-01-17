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
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	int T;
	cin >> T;
	sort(t.begin(), t.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int j = lower_bound(t.begin(), t.end(), t[i] + T + 1) - t.begin();
		ret = max(ret, j - i);
	}
	cout << ret << endl;
	return 0;
}

