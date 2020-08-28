/*
ID: frankzh1
TASK: skidesign
LANG: C++
 */
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

int n;
vector<int> height;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    cin >> n;
    height.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    sort(height.begin(), height.end());
    int res = 1 << 30;
    for (int i = height[0]; i <= height[n - 1]; i++) {
        int lo = i, hi = i + 17, sum = 0;
        for (int j = 0; j < n; j++) {
            if (height[j] < lo) {
                sum += (lo - height[j]) * (lo - height[j]);
            } else if (height[j] > hi) {
                sum += (height[j] - hi) * (height[j] - hi);
            }
        }
        res = min(res, sum);
    }
    cout << res << endl;
    return 0;
}

