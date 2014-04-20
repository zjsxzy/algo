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

const int MAXN = 105;
int n, m;
int price[MAXN];
vector<int> auc;
int main() {
	cin >> n >> m;
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
		sum += price[i];
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		auc.push_back(price[x]);
		sum -= price[x];
	}
	sort(auc.rbegin(), auc.rend());
	for (int i = 0; i < auc.size(); i++) {
		if (sum > auc[i]) {
			sum += sum;
		} else {
			sum += auc[i];
		}
	}
	cout << sum << endl;
	return 0;
}

