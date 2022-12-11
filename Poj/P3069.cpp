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
    int n, r;
    while (cin >> r >> n) {
        if (n == -1) break;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        sort(x.begin(), x.end());

        int i = 0, res = 0;
        while (i < n) {
            int s = x[i];
            i++;
            while (i < n && x[i] <= s + r) i++;
            int p = x[i - 1];
            while (i < n && x[i] <= p + r) i++;
            res++;
        }
        cout << res << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}
