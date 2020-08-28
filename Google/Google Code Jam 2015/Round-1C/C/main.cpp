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

LL C, D, V;
LL val[100];
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        cin >> C >> D >> V;
        for (int i = 0; i < D; i++) {
            cin >> val[i];
        }
        LL N = 0;
        int res = 0, i = 0;
        while (N < V) {
            LL x = N + 1;
            if (i < D && val[i] <= x) {
                N += val[i] * C;
                i++;
            } else {
                res++;
                N += x * C;
            }
        }
        printf("Case #%d: %d\n", cas, res);
    }
	return 0;
}

