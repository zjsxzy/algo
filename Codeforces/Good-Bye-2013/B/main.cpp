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

const int MAXN = 300 + 5;
int a[MAXN];
int n;

int main() {
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int dir = 0, pos = 1;
	string res = "";
	while (sum) {
		if (a[pos] > 0) {
			a[pos]--;
			sum--;
			res += "P";
		}
		if (dir == 0) {
			if (pos == n) {
				dir = 1;
				pos--;
				res += "L";
			} else {
				pos++;
				res += "R";
			}
		} else {
			if (pos == 1) {
				dir = 0;
				pos++;
				res += "R";
			} else {
				pos--;
				res += "L";
			}
		}
	}
	cout << res << endl;
	return 0;
}

