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

const LL INF = 1e18;
int n;
LL k, pos_sz, neg_sz, zeros;
vector<LL> neg, pos;

// how many values lower than x
LL count(LL val) {
    if (val == 0) {
        return neg_sz * pos_sz; 
    } else if (val > 0) {
        LL sum = zeros * (neg_sz + pos_sz) + neg_sz * pos_sz;
        for (auto px : pos) {
            LL t = val / px;
            LL cnt = lower_bound(pos.begin(), pos.end(), t) - pos.begin();
            sum += cnt;
        }
        return sum;
    } else if (val < 0) {
        LL sum = 0;
        for (auto nx : neg) {
            LL t = val / nx;
            LL cnt = lower_bound(pos.begin(), pos.end(), t) - pos.begin();
            sum += pos_sz - cnt;
        }
        return sum;
    }
}

int main() {
    cin >> n >> k;
    zeros = 0;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(x);
        else zeros++;
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.begin());
    LL pos_sz = (LL)pos.size(), neg_sz = (LL)neg.size();

    cout << count(8) << endl;
    /*
    LL lo = -INF, hi = INF;
    LL res;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (count(mid) <= k) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
    */
    return 0;
}