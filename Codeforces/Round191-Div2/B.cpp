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

int vst[10000007];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 2, j = 0; i <= 10000000; i++) {
		if (!vst[i]) {
			ans.push_back(i);
			j++;
			if (j == n) break;
			for (int k = 2; i * k <= 10000000; k++)
				vst[i * k] = 1;
		}
	}
	for (int i = 0; i < ans.size(); i++) 
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}