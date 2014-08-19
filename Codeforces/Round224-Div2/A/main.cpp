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

int main() {
	string s;
	cin >> s;
	int l = 0, r = 0;
	bool flag = false;
	string sl = "", sr = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '|') {
			flag = true;
			continue;
		}
		if (!flag) {
			sl += s[i];
			l++;
		}
		else {
			sr += s[i];
			r++;
		}
	}
	string t;
	cin >> t;

	int diff = abs(l - r);
	if (t.size() % 2 != diff % 2) puts("Impossible");
	else {
		int a = (t.size() + r - l) / 2, b = t.size() - a;
		if (a >= 0 && b >= 0) {
			for (int i = 0; i < a; i++) {
				sl += t[i];
			}
			for (int i = a; i < t.size(); i++) {
				sr += t[i];
			}
			cout << sl << "|" << sr << endl;
		} else {
			puts("Impossible");
		}
	}
	return 0;
}

