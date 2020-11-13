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

const int MAXN = 1000005;
int n, m;
int r[MAXN], d[MAXN], s[MAXN], t[MAXN];
LL day[MAXN];

bool check(int k) {
    memset(day, 0, sizeof(day));
    for (int i = 0; i < k; i++) {
        day[s[i]] += d[i];
        day[t[i] + 1] -= d[i];
    }
    if (day[1] > r[1]) return false;
    for (int i = 2; i <= n; i++) {
        day[i] += day[i - 1];
        if (day[i] > r[i]) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> s[i] >> t[i];
    }

    int lo = 0, hi = m, res = 0;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (res == m) {
        cout << 0 << endl;
    } else if (res == 0) {
        cout << -1 << endl;
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
        cout << res + 1 << endl;
    }
    return 0;
}