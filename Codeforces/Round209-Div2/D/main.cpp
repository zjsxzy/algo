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

const int maxn = 300000 + 5;
int n;
int a[maxn], succ[maxn], nxt[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	succ[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) succ[i] = succ[i - 1];
		else {
			int j = i - 1;
			for (; j > 0 && a[j] % a[i] == 0; j = succ[j] - 1);
			succ[i] = j + 1;
		}
	}

	nxt[n] = n;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
		else {
			int j = i + 1;
			for (; j <= n && a[j] % a[i] == 0; j = nxt[j] + 1);
			nxt[i] = j - 1;
		}
	}
	
	LL res = 0;
	for (int i = 1; i <= n; i++) {
		if (nxt[i] - succ[i] > res)
			res = nxt[i] - succ[i];
	}
	set<int> ans;
	for (int i = 1; i <= n; i++) {
		if (nxt[i] - succ[i] == res)
			ans.insert(succ[i]);
	}
	cout << ans.size() << " " << res << endl;
	for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		if (it != ans.begin()) cout << " ";
		cout << *it;
	}
	cout << endl;
	return 0;
}
