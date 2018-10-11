/*
ID: frankzh1
TASK: combo
LANG: C++
 */
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

const int MAXN = 105;
int n;
int a, b, c, d, e, f;
bool vst[MAXN][MAXN][MAXN];

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> n;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    int res = 0;
    for (int i = a - 2; i <= a + 2; i++) {
        for (int j = b - 2; j <= b + 2; j++) {
            for (int k = c - 2; k <= c + 2; k++) {
                if (!vst[(i + n) % n][(j + n) % n][(k + n) % n]) {
                    res++;
                    vst[(i + n) % n][(j + n) % n][(k + n) % n] = true;
                }
            }
        }
    }
    for (int i = d - 2; i <= d + 2; i++) {
        for (int j = e - 2; j <= e + 2; j++) {
            for (int k = f - 2; k <= f + 2; k++) {
                if (!vst[(i + n) % n][(j + n) % n][(k + n) % n]) {
                    res++;
                    vst[(i + n) % n][(j + n) % n][(k + n) % n] = true;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

