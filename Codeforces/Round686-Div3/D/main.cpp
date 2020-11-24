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
    LL n;
    cin >> n;
    LL N = n;
    map<int, int> cnt;
    LL t = (LL)sqrt(n);
    for (LL d = 2; d <= t; d++) {
        LL sum = 0;
        while (n % d == 0) {
            cnt[d]++;
            n /= d;
        }
    }
    LL mx = 0, val;
    for (auto x : cnt) {
        if (x.second > mx) {
            mx = x.second;
            val = x.first;
        }
    }
    if (mx <= 1) {
        cout << 1 << endl;
        cout << N << endl;
    } else {
        cout << mx << endl;
        for (int i = 0; i < mx - 1; i++) {
            cout << val << " ";
            N /= val;
        }
        cout << N << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

