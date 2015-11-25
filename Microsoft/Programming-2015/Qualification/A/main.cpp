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
#include <cassert>
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

map<string, int> mp;
void init() {
	mp["January"] = 1; mp["February"] = 2; mp["March"] = 3; mp["April"] = 4;
	mp["May"] = 5; mp["June"] = 6; mp["July"] = 7; mp["August"] = 8;
	mp["September"] = 9; mp["October"] = 10; mp["November"] = 11; mp["December"] = 12;
}
int check(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int calculate(int year, int month, int day) {
	int ret = year / 4 - year / 100 + year / 400;
	if (check(year) && (month < 2 || (month == 2 && day < 29))) ret--;
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	init();
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		string month1, month2, coma;
		int day1, day2, year1, year2;
		cin >> month1 >> day1 >> coma >> year1;
		cin >> month2 >> day2 >> coma >> year2;
		int ret = calculate(year2, mp[month2], day2) - calculate(year1, mp[month1], day1);
		if (mp[month1] == 2 && day1 == 29) ret++;
		// cout << month << " " << day << " " << year << endl;
		cout << ret << endl;
		// cout << calculate(year2, mp[month2], day2) << " " << calculate(year1, mp[month1], day1) << " " << ret << endl;
	}
	return 0;
}

