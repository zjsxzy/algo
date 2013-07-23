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

int a[111], sum[111];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int tot = sum[j] - sum[i - 1];
			int temp = sum[n] - tot + (j - i + 1 - tot);
			if (temp > ret) ret = temp;
		}
	}
	cout << ret << endl;
	return 0;
}