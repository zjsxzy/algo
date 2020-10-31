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

int n, k;

LL f(int x) {
    int l = max(1, x - n), r = min(x - 1, n);
    //cout << l << " " << r << endl;
    return r - l + 1;
}

int main() {
    cin >> n >> k;
    LL res = 0;
    for (int x = 2; x <= n << 1; x++) {
        int y = x - k;
        if (y >= 2 && y <= (n << 1)) {
            // cout << x << " " << f(x) << " " << y << " " << f(y) << endl;
            res += f(x) * f(y);
        }
    }
    cout << res << endl;
    return 0;
}

