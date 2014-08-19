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

int main() {
	char st[12][12] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

	char input[10];
	int cas = 1;
	while (~scanf("%s\n", input)) {
		printf("Case %d: ", cas++);
		for (int i = 0; i < 12; i++) {
			if (strcmp(input, st[i]) == 0) {
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}