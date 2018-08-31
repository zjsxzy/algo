/*
ID: frankzh1
TASK: milk2
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

const int MAXN = 1000000 + 5;
int n;
int vst[MAXN];

pair<int, int> check(int minl, int maxr) {
    if (n == 1) return MP(maxr - minl, 0);
    int st = minl, ed = -1, ans1 = 0, ans2 = 0;
    bool flag = true;
    for (int i = st + 1; i <= maxr; i++) {
        if (!flag) {
            if (vst[i] && ed != -1) {
                cout << i << endl;
                ans2 = max(ans2, i - ed);
                st = i;
                flag = true;
            }
        } else {
            if (!vst[i]) {
                ans1 = max(ans1, i - st);
                ed = i;
                flag = false;
            }
        }
    }
    return MP(ans1, ans2);
}

int main() {
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    cin >> n;
    int minl = MAXN, maxr = 0;
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        minl = min(minl, l);
        maxr = max(maxr, r);
        for (int j = l; j < r; j++) {
            vst[j]++;
        }
    }

    pair<int, int> ans = check(minl, maxr);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
