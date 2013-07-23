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

int n, m;
string mat[505];
bool vst[505][505];
vector<pair<char, pair<int, int> > > ans;

void dfs(int i, int j, bool flag) {
	if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == '#' || vst[i][j]) return;

	vst[i][j] = true;
	ans.PB(MP('B', MP(i + 1, j + 1)));
	dfs(i + 1, j, true);
	dfs(i - 1, j, true);
	dfs(i, j + 1, true);
	dfs(i, j - 1, true);
	if (flag) {
		ans.PB(MP('D', MP(i + 1, j + 1)));
		ans.PB(MP('R', MP(i + 1, j + 1)));
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, false);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	}
	return 0;
}