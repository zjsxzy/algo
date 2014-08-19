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

int perfect(const string &s) {
	map<char, int> mp;
	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];
		ch = tolower(ch);
		mp[ch]++;
	}
	vector<int> cnt;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cnt.PB(it->second);
	}
	sort(cnt.rbegin(), cnt.rend());
	int ret = 0, cur = 26;
	for (int i = 0; i < cnt.size(); i++) {
		ret += cnt[i] * cur;
		cur--;
	}
	return ret;
}

int main() {
	cout << perfect("dad") << endl;
	return 0;
}

