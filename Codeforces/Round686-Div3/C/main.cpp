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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    int res = n;
    for (auto x : mp) {
        int m = x.second.size();
        int prev = -1, sum = 0;
        for (int i = 0; i < m; i++) {
            if (x.second[i] - prev > 1) {
                sum++;
            }
            prev = x.second[i];
        }
        if (x.second[m - 1] != n - 1) sum++;
        //cout << x.first << " " << sum << endl;
        res = min(res, sum);
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

