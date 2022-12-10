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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        LL res = (LL)n * (n + 1) / 2;
        LL sum = 0, cur = 1;
        while (cur <= n) {
            sum += cur;
            cur <<= 1;
        }
        cout << res - 2 * sum << endl;
    }
	return 0;
}

