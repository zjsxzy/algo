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
typedef long long LL;

const int maxn = 10005;
double l[maxn];
int n, k;

bool check (double x) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += (int)(l[i] / x);
    }
    return num >= k;
}

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", l + i);
    }
    double lo = 0, hi = 1e6;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.2f\n", floor(hi * 100) / 100);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}
