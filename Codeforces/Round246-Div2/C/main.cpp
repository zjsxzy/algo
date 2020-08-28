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

const int MAXN = 100000 + 5;
int n;
int a[MAXN], pos[MAXN];
bool isPrime[MAXN];

void getPrime() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= MAXN - 5; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j <= MAXN - 5; j += i) {
			isPrime[j] = false;
		}
	}
}

void Swap(int i, int j) {
	swap(pos[a[i]], pos[a[j]]);
	swap(a[i], a[j]);
}

int main() {
	getPrime();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<pair<int, int> > ret;
	for (int i = 1; i <= n; i++) {
		while (pos[i] != i) {
			int j;
			for (j = pos[i] - i + 1; !isPrime[j]; j--);
			ret.PB(MP(pos[i] - j + 1, pos[i]));
			Swap(pos[i], pos[i] - j + 1);
		}
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i].first << " " << ret[i].second << endl;
	}
	return 0;
}

