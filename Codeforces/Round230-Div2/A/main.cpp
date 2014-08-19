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

int cnt[30];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
	}
	int ret = (cnt['n' - 'a'] - 1) / 2;
	ret = min(ret, cnt['i' - 'a']);
	ret = min(ret, cnt['e' - 'a'] / 3);
	ret = min(ret, cnt['t' - 'a']);
	cout << ret << endl;
	return 0;
}

