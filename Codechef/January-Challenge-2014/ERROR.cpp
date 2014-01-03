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

const int MAXN = 100000 + 5;
char str[MAXN];
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%s", str);
		int len = strlen(str);
		bool bad = true;
		for (int i = 0; i + 2 < len; i++) {
			if (str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0') {
				bad = false;
				break;
			}
			if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '1') {
				bad = false;
				break;
			}
		}
		puts(bad ? "Bad" : "Good");
	}
	return 0;
}

