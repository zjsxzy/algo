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
    int n;
    cin >> n;
    if (n == 1) cout << 0 << endl;
    else if (n == 2) cout << 1 << endl;
    else if (n == 3 || n % 2 == 0) cout << 2 << endl;
    else cout << 3 << endl;
    return;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

