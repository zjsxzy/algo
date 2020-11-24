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
    map<int, int> cnt, idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        idx[a[i]] = i + 1;
    }
    int value = INT_MAX;
    for (auto x : cnt) {
        if (x.second == 1) {
            if (x.first < value) {
                value = x.first;
            }
        }
    }
    if (value == INT_MAX) cout << -1 << endl;
    else cout << idx[value] << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

