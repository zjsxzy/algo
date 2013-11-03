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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(2 * n);
	vector<int> ans(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		ans[i] = i + 1;
	}
	for (int i = 1, p = 0; i <= k; i++, p += 2)
		swap(ans[p], ans[p + 1]);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
		if (i == ans.size() - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}
