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

LL n;

int main() {
    cin >> n;
    set<LL> a3;
    map<LL, int> mp;
    LL t = 1;
    for (int i = 1; t <= n; i++) {
        t = t * 3;
        a3.insert(t);
        mp[t] = i;
    }
    t = 1;
    for (int i = 1; t <= n; i++) {
        t = t * 5;
        if (a3.find(n - t) != a3.end()) {
            cout << mp[n - t] << " " << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

