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

const int MAXN = 1000 + 5;
int n;
int card[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	int l = 0, r = n - 1;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		if (card[l] > card[r]) {
			temp = card[l++];
		} else {
			temp = card[r--];
		}
		if (i & 1) b += temp;
		else a += temp;
	}
	cout << a << " " << b << endl;
	return 0;
}

