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

bool check(LL p, LL q, LL a) {
	return p / q == a;
}

int main(int argc, char const *argv[])
{
	LL p, q;
	cin >> p >> q;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (q == 0) {
			cout << "NO" << endl;
			return 0;
		}
		if (i == n - 2 && a[i + 1] == 1) {
			if (p / q != a[i] + 1) {
				cout << "NO" << endl;
				return 0;
			}
		} else if (!check(p, q, a[i])) {
			cout << "NO" << endl;
			return 0;
		}
		if (a[i] * q < 0) {
			cout << "NO" << endl;
			return 0;
		}
		p -= a[i] * q;
		swap(p, q);
	}
	cout << "YES" << endl;
	return 0;
}