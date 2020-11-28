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

void solve() {
    LL n;
    cin >> n;
    /*
    LL a = 1, b = 1, c = -(2LL * n + 2);
    LL s = b * b - 4LL * a * c;
    LL t = sqrt(s);
    LL k = (-b + t) / 2;
    */
    LL lo = 1, hi = sqrt(2LL * n + 2) + 1;
    LL k = -1;
    while (lo <= hi) {
        LL mid = (lo + hi) / 2;
        if (mid * (mid + 1) <= 2LL * n + 2) {
            k = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << n + 1 - k << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

