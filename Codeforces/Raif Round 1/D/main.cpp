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
int a[MAXN];

void solve() {
    vector<int> one, two, thr;
    vector<pair<int, int> > res;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            res.PB({i, i});
            one.PB(i);
        } else if (a[i] == 2) {
            int c;
            if (one.size() > 0) {
                c = one.back();
                one.pop_back();
            } else {
                cout << -1 << endl;
                return;
            }
            res.PB({c, i});
            two.PB(i);
        } else if (a[i] == 3) {
            int c;
            if (thr.size() > 0) {
                c = thr.back();
                thr.pop_back();
            } else if (two.size() > 0) {
                c = two.back();
                two.pop_back();
            } else if (one.size() > 0) {
                c = one.back();
                one.pop_back();
            } else {
                cout << -1 << endl;
                return;
            }
            res.PB({i, i});
            res.PB({i, c});
            thr.PB(i);
        }
    }

    cout << res.size() << endl;
    for (auto x : res) {
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}
