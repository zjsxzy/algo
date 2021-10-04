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

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		int n;
		LL k;
		cin >> n >> k;
		vector<LL> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		LL ret = 1ll << 60;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (abs(a[i] + a[j] - k) < ret) {
					ret = abs(a[i] + a[j] - k);
					sum = 1;
				} else if (abs(a[i] + a[j] - k) == ret) {
					sum++;
				}
			}
		}
		cout << ret << " " << sum << endl;
	}
	return 0;
}

