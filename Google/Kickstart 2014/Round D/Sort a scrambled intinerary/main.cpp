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
int n, m;
int deg[MAXN];
string name[MAXN], destination[MAXN];
map<string, int> city;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		city.clear();
		n = 0;
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < MAXN; i++) {
			name[i] = "#"; destination[i] = "#";
		}
		printf("Case #%d:", cas);
		cin >> m;
		for (int i = 0; i < m; i++) {
			string src, des;
			cin >> src >> des;
			if (city.find(src) == city.end()) {
				city[src] = n++;
			}
			if (city.find(des) == city.end()) {
				city[des] = n++;
			}
			name[city[src]] = src; name[city[des]] = des;
			destination[city[src]] = des;
			deg[city[des]]++;
		}
		int start = 0;
		for (int i = 0; i < n; i++) {
			if (deg[i] == 0) {
				start = i;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (destination[start] == "#") break;
			cout << " " << name[start] << "-" << destination[start];
			start = city[destination[start]];
		}
		cout << endl;
	}
	return 0;
}

