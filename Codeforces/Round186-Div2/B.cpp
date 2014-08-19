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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(n + 5), sum(n + 5);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) cnt[i + 1] = 1;
		sum[i + 1] = sum[i] + cnt[i + 1];
	}
	// FOREACH(it, cnt) cout << *it;
	// cout << endl;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}
	return 0;
}