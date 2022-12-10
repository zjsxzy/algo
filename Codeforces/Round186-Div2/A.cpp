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

int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	if (num >= 0) cout << num << endl;
	else {
		num *= -1;
		if (num < 10) cout << -num << endl;
		else {
			int ret = min(num / 10, num / 100 * 10 + num % 10);
			cout << -ret << endl;
		}
	}
	return 0;
}