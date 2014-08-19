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

string numToString(int x) {
	stringstream ss;
	ss << x;
	string ret = ss.str();
	return ret;
}

string calculate(int a, int b, int c) {
	if (c >= a + b) {
		string ret = "1/1";
		return ret;
	}
	int denominator = a * b * 2;
	int numerator = c * c;
	if (a < c) {
		numerator -= (c - a) * (c - a);
	}
	if (b < c) {
		numerator -= (c - b) * (c - b);
	}
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	string ret = numToString(numerator);
	ret += "/";
	ret += numToString(denominator);
	return ret;
}

int main() {
	cout << calculate(4, 4, 4) << endl;
	return 0;
}
