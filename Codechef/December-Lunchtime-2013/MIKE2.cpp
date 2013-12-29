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

const int MAXN = 1000000 + 5;
int n;
LL X;
LL task[MAXN], half[MAXN];

int main() {
	while (cin >> n >> X) {
		for (int i = 0; i < n; i++) {
			cin >> task[i];
			if (task[i] & 1) half[i] = (task[i] + 1) / 2;
			else half[i] = task[i] / 2;
			task[i] = task[i] - half[i];
		}
		sort(half, half + n);
		sort(task, task + n);
		int mn = n, mx = 0;
		LL sum = 0;
		for (int i = 0; i < n && sum + half[i] <= X; i++) {
			mn--;
			sum += half[i];
		}
		for (int i = 0; i < n && sum + task[i] <= X; i++) {
			mx++;
			sum += task[i];
		}
		cout << mn << " " << mx << endl;
	}
	return 0;
}

