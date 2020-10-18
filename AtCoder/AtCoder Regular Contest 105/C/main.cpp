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

int n, m;

int main() {
    cin >> n >> m;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    int max_weight = *max_element(weight.begin(), weight.end());
    vector<int> sum(1 << n), len(1 << n);
    for (int s = 0; s < (1 << n); s++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                x += weight[i];
            }
        }
        sum[s] = x;
    }
    for (int i = 0; i < m; i++) {
        int l, v;
        cin >> l >> v;
        if (v < max_weight) {
            cout << -1 << endl;
            return 0;
        }
        for (int s = 0; s < (1 << n); s++) {
            if (sum[s] > v) {
                len[s] = max(len[s], l);
            }
        }
    }

    int res = INT_MAX;
    vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }

    do {
        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            int s = (1 << perm[i]);
            for (int j = i - 1; j >= 0; j--) {
                s |= (1 << perm[j]);
                dp[i] = max(dp[i], dp[j] + len[s]);
            }
        }
        res = min(res, dp[n - 1]);
    } while(next_permutation(perm.begin(), perm.end()));
    cout << res << endl;
    return 0;
}
