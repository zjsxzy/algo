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

int a[1005];
int main() {
	int n = 1000;
	int ones = 500;
	int twos = 300;
	int threes = 100;
	int rest = n - ones - twos - threes;
	printf("1");
	for (int i = 0; i < ones; i++) {
		a[rand() % 1000] = 1;
	}
	for (int i = 0; i < twos; i++) {
		a[rand() % 1000] = 2;
	}
	for (int i = 0; i < threes; i++) {
		a[rand() % 1000] = 3;
	}
	for (int i = 0; i < rest; i++) {
		a[rand() % 1000] = rand() % 1000 + 1;
	}
	for (int i = 0; i < 999; i++) {
		if (a[i] == 0) a[i] = 1;
		printf(",%d", a[i]);
	}
	printf("");
	return 0;
}

