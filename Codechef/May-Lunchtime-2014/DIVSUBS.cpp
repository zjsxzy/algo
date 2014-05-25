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

const int MAXN = 100000 + 5;
int n;
int prefix[MAXN];
int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n;
		memset(prefix, 0, sizeof(prefix));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			prefix[i] = (prefix[i - 1] + x % n) % n;
		}
		map<int, int> mp;
		for (int i = 0; i <= n; i++) {
			if (mp.find(prefix[i]) == mp.end()) {
				mp[prefix[i]] = i;
			} else {
				int l = mp[prefix[i]] + 1, r = i;
				cout << r - l + 1 << endl;;
				for (int k = l; k < r; k++)
					cout << k << " ";
				cout << r << endl;
				break;
			}
		}
	}
	return 0;
}

