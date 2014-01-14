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

const int MAXN = 100000 + 5;
int n;
int a[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int max = a[n - 1];
	vector<int> fi, se;
	int pf = max, ps = max;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < pf) {
			fi.PB(a[i]);
			pf = a[i];
		} else if (a[i] < ps) {
			se.PB(a[i]);
			ps = a[i];
		}
	}
	cout << fi.size() + se.size() + 1 << endl;
	for (int i = fi.size() - 1; i >= 0; i--) {
		cout << fi[i] << " ";
	}
	cout << max;
	for (int i = 0; i < se.size(); i++) {
		cout << " " << se[i];
	}
	cout << endl;
	return 0;
}

