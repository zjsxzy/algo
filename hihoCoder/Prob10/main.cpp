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

string PostOrder;

void GetPostOrder(const string &PreOrder, const string &InOrder) {
	//cout << PreOrder << " " << InOrder << " " << PostOrder << endl;
	int n = PreOrder.size();
	if (n == 0) return;
	if (n == 1) {
		PostOrder += PreOrder[0];
		return;
	}

	int k = -1;
	char root = PreOrder[0];
	// cout << root << endl;
	for (int i = 0; i < n; i++) {
		if (root == InOrder[i]) {
			k = i;
			break;
		}
	}
	string PreSub = PreOrder.substr(1, k);
	string InSub = InOrder.substr(0, k);
	GetPostOrder(PreSub, InSub);

	if (k + 1 < n) {
		PreSub = PreOrder.substr(k + 1, n - k - 1);
		InSub = InOrder.substr(k + 1, n - k - 1);
		GetPostOrder(PreSub, InSub);
	}

	PostOrder += root;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string PreOrder, InOrder;
	string a, b;
	cin >> a >> b;
	cout << a + b << endl;
	cin >> PreOrder >> InOrder;
	PostOrder = "";
	GetPostOrder(PreOrder, InOrder);
	cout << PostOrder << endl;
	return 0;
}
