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

int power(int x, int a) {
	int ret = 1;
	for (int i = 0; i < a; i++)
		ret *= x;
	return ret;
}

int sumDig(LL x) {
	int ret = 0;
	for (; x; x /= 10) {
		ret += x % 10;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif
	int a, b, c;
	cin >> a >> b >> c;
	set<int> st;
	for (int s = 1; s <= 81; s++) {
		LL x = (LL)b * power(s, a) + c;
		if (x < 1000000000 && sumDig(x) == s) {
			st.insert((int)x);
		}
	}
	cout << st.size() << endl;
	FOREACH(it, st) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

