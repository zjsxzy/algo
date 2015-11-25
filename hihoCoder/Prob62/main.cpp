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

const int MAXN = 20000 + 5;
const int MAXM = 5000 + 5;
int n, m;
string website[MAXN];
map<string, int> lastvis;
int main() {
	cin >> n >> m;
	int s = 0, cache = 0;
	for (int i = 0; i < n; i++) {
		cin >> website[i];
		if (lastvis.find(website[i]) == lastvis.end()) {
			cout << "Internet" << endl;
			cache++;
			if (cache > m) s++;
		} else if (lastvis[website[i]] >= s) {
			cout << "Cache" << endl;
		} else {
			cache++;
			if (cache > m) s++;
			cout << "Internet" << endl;
		}
		lastvis[website[i]] = i;
		while (lastvis[website[s]] != s) {
			s++;
		}
	}
	return 0;
}
