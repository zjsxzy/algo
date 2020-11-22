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

void solve() {
    int n, k;
    cin >> n >> k;
    map<char, int> cs, ct;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        cs[s[i]]++;
        ct[t[i]]++;
    }

    int sums = 0, sumt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        sums += cs[c];
        sumt += ct[c];
        if (sums < sumt || sums % k != sumt % k) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

