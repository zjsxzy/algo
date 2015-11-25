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

int n = 20, m = 200, k = 15;
bool adj[22][22];
int main() {
	freopen("in.txt", "w", stdout);
	cout << 1 << endl;
	cout << n << " " << m << " " << k << endl;
	for (int i = 0; i < m; ) {
		int a = rand() % n + 1, b = rand() % n + 1;
		if (a != b && !adj[a][b] && !adj[b][a]) {
			cout << a << " " << b << endl;
			adj[a][b] = adj[b][a] = true;
			i++;
		}
		// cout << a << " " << b << endl;
	}
	return 0;
}

