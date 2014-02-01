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

string str;

int compare(int s1, int e1, int s2, int e2) {
	if (e1 - s1 > e2 - s2) return 1;
	if (e1 - s1 < e2 - s2) return -1;

	for (int i = s1, j = s2; i <= e1; i++, j++) {
		if (str[i] - '0' > str[j] - '0') return 1;
		if (str[i] - '0' < str[j] - '0') return -1;
	}
	return 0;
}

int main() {
	cin >> str;
	int n = str.size(), ret = 0, mid = n - 1;
	for (int i = n - 1; i >= 1; i--) {
		if (str[i] != '0') {
			if (compare(0, i - 1, i, mid) < 0)
				break;
			ret++;
			mid = i - 1;
		}
	}
	ret++;
	cout << ret << endl;
	return 0;
}

