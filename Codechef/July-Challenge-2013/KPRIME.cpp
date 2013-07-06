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

const int MAXN = 100000;
int p[MAXN + 5];
int sum[6][MAXN + 5];
void prepare() {
	for (int i = 2; i <= MAXN; i++) {
		if (p[i] == 0) {
			p[i] = 1;
			for (int j = 2; i * j <= MAXN; j++) {
				p[i * j]++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	prepare();
	memset(sum, 0, sizeof(sum));
	for (int i = 2; i <= MAXN; i++) {
		for (int k = 1; k <= 5; k++) {
			sum[k][i] = sum[k][i - 1] + (p[i] == k);
		}
	}
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int A, B, k;
		scanf("%d%d%d", &A, &B, &k);
		printf("%d\n", sum[k][B] - sum[k][A - 1]);
	}
	return 0;
}