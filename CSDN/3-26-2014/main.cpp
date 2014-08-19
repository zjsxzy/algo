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

string s, t;
int main() {
	while (cin >> s >> t) {
		int n = s.size();
		LL ret = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				LL cnt = (LL)('9' - t[i]);
				for (int j = i + 1; j < n; j++)
					cnt *= (s[j] == '?' ? 10ll : 1ll);
				ret += cnt;
			} else if (s[i] > t[i]) {
				LL cnt = 1ll;
				for (int j = i + 1; j < n; j++)
					cnt *= (s[j] == '?' ? 10ll : 1ll);
				ret += cnt;
				break;
			} else if (s[i] < t[i]) break;
		}
		cout << ret << endl;
	}
	return 0;
}

