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

struct auction {
	int price, idx;
	auction() {}
	auction(int price, int idx) : price(price), idx(idx) {}
	bool operator < (const auction &pt) const {
		return price > pt.price;
	}
};
int main() {
	int n;
	cin >> n;
	vector<auction> v(n);
	for (int i = 0; i < n; i++) {
		v[i].idx = i + 1;
		cin >> v[i].price;
	}
	sort(v.begin(), v.end());
	cout << v[0].idx << " " << v[1].price << endl;
	return 0;
}

