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
int a[MAXN];
int n, k;

void solve() {
    sort(a, a + n);
    long long mx = a[n - 1];
    for (int i = 1; i <= k; i++) {
        mx += (long long)a[n - i - 1];
    }
    cout << mx << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}

