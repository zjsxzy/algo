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

const int MAXN = 100005;
LL a[MAXN], cut[MAXN];
int n, k;

LL f(LL l, LL p) {
    LL x = l / p, y = l % p;
    return x * x * (p - y) + (x + 1) * (x + 1) * y;
}

int main() {
    cin >> n >> k;
    priority_queue<pair<LL, int> > pq;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += (LL)a[i] * a[i];
        cut[i] = 1;
        pq.push({f(a[i], cut[i]) - f(a[i], cut[i] + 1), i});
    }
    for (int i = 0; i < k - n; i++) {
        auto it = pq.top(); pq.pop();
        res -= it.first;
        int j = it.second;
        cut[j]++;
        pq.push({f(a[j], cut[j]) - f(a[j], cut[j] + 1), j});
    }
    cout << res << endl;
    return 0;
}

