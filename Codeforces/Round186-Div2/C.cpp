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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	vector<LL> sum(n+5);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	LL ret = 0;
	for (int i = 1; i <= n; i *= 4) {
		ret += (LL)sum[i];
	}
	cout << ret << endl;
	return 0;
}