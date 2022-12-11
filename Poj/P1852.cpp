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
typedef long long LL;

void solve() {
    int L, n;
    cin >> L >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int mn = INT_MIN, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        mn = max(mn, min(a[i], L - a[i]));
        mx = max(mx, max(a[i], L - a[i]));
    }
    cout << mn << ' ' << mx << endl;
}

int main() {
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}
