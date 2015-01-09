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

const int MAXN = 25;
int n, Gp, Gc, Gf;
int P[MAXN], C[MAXN], F[MAXN];
bool solve() {
    for (int mask = 0; mask < 1 << n; mask++) {
        int X = 0, Y = 0, Z = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                X += P[i];
                Y += C[i];
                Z += F[i];
            }
        }
        if (X == Gp && Y == Gc && Z == Gf) return true;
    }
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        cin >> Gp >> Gc >> Gf;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> P[i] >> C[i] >> F[i];
        }
        bool sol = solve();
        puts(sol ? "yes" : "no");
    }
	return 0;
}

