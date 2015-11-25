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

const int MAXN = 100000 + 5;
int K, N;
char str[MAXN];
int sum0[MAXN], sum1[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int ts;
    while (ts--) {
        scanf("%d%d%d", &N, &K, &Q);
        scanf("%s", str + 1);
        sum0[0] = sum1[0] = 0;
        for (int i = 1; i <= N; i++) {
            sum0[i] = sum0[i - 1] + (str[i] == '0');
            sum1[i] = sum1[i - 1] + (str[i] == '1');
        }
        for (int i = 0; i < Q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
        }
    }
	return 0;
}

