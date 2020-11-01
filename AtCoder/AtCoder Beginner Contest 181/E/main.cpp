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
int n, m;

int main() {
    cin >> n >> m;
    vector<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.push_back(x);
    }
    sort(h.begin(), h.end());

    vector<LL> l(n), r(n);
    for (int i = 0; i <= n / 2; i++) {
        l[i + 1] = l[i] + h[2*i+1] - h[2*i];
    }
    for (int i = n / 2; i > 0; i--) {
        r[i - 1] = r[i] + h[2*i] - h[2*i-1];
    }

    /*
    for (int i = 0; i <= n / 2; i++) {
        cout << i << " " << l[i] << " " << r[i] << endl;
    }
    */

    LL res = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int idx = lower_bound(h.begin(), h.end(), x) - h.begin();
        // cout << x << " " << idx << endl;
        int p = idx / 2;
        if (idx % 2 == 1) idx--;
        LL temp = l[p] + r[p] + abs(x - h[idx]);
        if (res == -1 || temp < res) res = temp;
    }
    cout << res << endl;
    return 0;
}

