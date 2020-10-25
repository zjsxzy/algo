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
int n;
int a[6];
int b[MAXN];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    cin >> n;
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < 6; j++) {
            if (b[i] > a[j])
                vec.PB({b[i] - a[j], i});
        }
    }
    int r = 0, res = INT_MAX;
    int tot = 0;
    vector<int> cnt(n);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        while (r < vec.size() && tot != n) {
            cnt[vec[r].second]++;
            if (cnt[vec[r].second] == 1) {
                tot++;
            }
            r++;
        }
        if (tot == n) {
            res = min(res, vec[r-1].first - vec[i].first);
        }
        cnt[vec[i].second]--;
        if (cnt[vec[i].second] == 0) {
            tot--;
        }
    }
    cout << res << endl;
    return 0;
}

