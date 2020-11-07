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

const int MAXN = 200005;
int n, k;
LL a[MAXN], b[MAXN];

bool check(LL x) {
    priority_queue<pair<LL, int> > pq;
    vector<int> charge(n);
    for (int i = 0; i < n; i++) {
        pq.push({-(a[i] / b[i] + 1), i});
    }
    for (int t = 1; t <= k; t++) {
        auto top = pq.top(); pq.pop();
        LL power_off_time = -top.first, index = top.second;
        // cout << t << " " << index << " " << power_off_time << endl;
        if (power_off_time < t) return false;
        charge[index]++;
        LL sum = a[index] + (LL)charge[index] * x;
        pq.push({-(sum / b[index] + 1), index});
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        // cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        // cin >> b[i];
    }
    LL lo = 0, hi = 1e13, res = -1;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}
