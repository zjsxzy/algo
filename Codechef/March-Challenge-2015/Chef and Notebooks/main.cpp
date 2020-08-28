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
    int ts;
	scanf("%d", &ts);
    while (ts--) {
        int X, Y, N, K;
		scanf("%d%d%d%d", &X, &Y, &K, &N);
        bool flag = false;
        for (int i = 0; i < N; i++) {
            int P, C;
			scanf("%d%d", &P, &C);
            if (C <= K && P + Y >= X) {
                flag = true;
            }
        }
        puts(flag ? "LuckyChef" : "UnluckyChef");
    }
	return 0;
}

