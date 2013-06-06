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

int gcd1(int a, int b) {
	int r = a, rp = b;
	while (rp != 0) {
		int rpp = r % rp;
		r = rp;
		rp = rpp;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << gcd1(a, b) << endl;
	return 0;
}