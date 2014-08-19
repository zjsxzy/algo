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

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> d(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int mask[3] = {0, 0, };
	for (int i = 0; i < n; i++) {
		int a = d[i] % 10, b = d[i] / 10 % 10, c = d[i] / 100;
		if (a != 0 && mask[0] == 1) continue;
		if (b != 0 && mask[1] == 1) continue;
		if (c != 0 && mask[2] == 1) continue;
		ans.push_back(d[i]);
		if (a != 0) mask[0] = 1;
		if (b != 0) mask[1] = 1;
		if (c != 0) mask[2] = 1;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}