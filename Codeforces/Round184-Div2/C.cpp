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
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	LL ret = 0, last = -1;
	FOREACH(it, mp) {
		//cout << it->first << " " << it->second << endl;
		if (it->second > 0) mp[it->first + 1] += it->second / 2;
		if (it->second % 2 == 0) continue;
		ret += it->first - last - 1;
		last = it->first;
	}
	cout << ret << endl;
	return 0;
}