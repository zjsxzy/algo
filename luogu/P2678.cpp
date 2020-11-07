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

const int MAXN = 50005;
int L, n, m;
int dist[MAXN];

bool check(int x) {
    int sum = 0, cur = 0;
    for (int i = 0; i <= n; i++) {
        while (i <= n && dist[i] - cur < x) {
            i++;
            sum++;
        }
        if (i == n + 1) {
            return sum <= m;
        }
        cur = dist[i];
    }
    return sum <= m;
}

int main() {
    cin >> L >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    dist[n] = L;

    int lo = 0, hi = L, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1; // 注意会否越界，这题不会
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}

