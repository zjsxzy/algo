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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int g = a[0];
	int maxval = a[0];
	for (int i = 1; i < n; i++) {
		g = gcd(g, a[i]);
		maxval = max(maxval, a[i]);
	}
	
	int round = maxval / g - n;
	if (round % 2 == 0) puts("Bob");
	else puts("Alice");
	return 0;
}
