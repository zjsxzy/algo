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
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL sum = 0;
    for (int i = 1; i < n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    LL res = sum;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            res = min(res, sum - abs(a[i] - a[i + 1]));
        } else if (i == n - 1) {
            res = min(res, sum - abs(a[i] - a[i - 1]));
        } else {
            LL t = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
            res = min(res, sum - t + abs(a[i + 1] - a[i - 1]));
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

