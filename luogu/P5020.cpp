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

const int MAXN = 105;
const int MAXM = 25005;
int n;
int a[MAXN];
bool dp[MAXM];

void solve() {
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (dp[a[i]]) {
            sum++;
        }
        for (int j = a[i]; j <= a[n - 1]; j++) {
            dp[j] = dp[j] | dp[j - a[i]];
        }
    }
    cout << n - sum << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}

