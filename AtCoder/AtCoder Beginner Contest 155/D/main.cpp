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

// how many values lower than or equal to x
LL count(LL val) {
    LL sum = 0;
    if (val == 0) {
        sum = neg_sz * pos_sz;
    } else if (val > 0) {
        sum = zeros * (neg_sz + pos_sz) + neg_sz * pos_sz + zeros * (zeros - 1) / 2;
        // cout << sum << endl;
        for (int i = 0; i < pos_sz; i++) {
            LL px = pos[i];
            LL t = val / px;
            LL cnt = upper_bound(pos.begin(), pos.end(), t) - pos.begin();
            // cout << px << " " << t << " " << cnt << endl;
            if (cnt > i) {
                sum += cnt - i - 1;
            }
        }
        // cout << sum << endl;
        for (int i = 0; i < neg_sz; i++) {
            LL nx = neg[i];
            LL t = val / nx;
            LL cnt = lower_bound(neg.begin(), neg.end(), t) - neg.begin();
            // cout << t << " " << cnt << endl;
            if (cnt > i) {
                sum += neg_sz - cnt;
            } else {
                sum += neg_sz - i - 1;
            }
        }
        // cout << sum << endl;
    } else if (val < 0) {
        for (int i = 0; i < neg_sz; i++) {
            LL nx = neg[i];
            LL t = val / nx;
            LL cnt = upper_bound(pos.begin(), pos.end(), t) - pos.begin();
            // cout << t << " " << cnt << endl;
            sum += pos_sz - cnt;
        }
    }
    return sum;
}

int main() {
    cin >> n >> k;
    zeros = 0;
    map<LL, int> cnt;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        cnt[x]++;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(x);
        else zeros++;
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    pos_sz = (LL)pos.size(), neg_sz = (LL)neg.size();

    LL lo = -INF, hi = INF;
    LL res;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        LL t = count(mid);
        if (t >= k) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    bool find = false;
    for (auto x : cnt) {
        if (x.first != 0 && res % x.first == 0) {
            int r = res / x.first;
            if (r == x.first) {
                if (cnt[r] > 1) find = true;
            } else {
                if (cnt.find(r) != cnt.end()) {
                    find = true;
                }
            }
        }
    }
    if (!find) res--;
    //cout << find << endl;
    //cout << res << " " << lo << " " << hi << endl;
    cout << res << endl;
    return 0;
}
