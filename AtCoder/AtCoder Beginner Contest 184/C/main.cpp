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
    LL r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    LL dx = abs(r1 - r2);
    LL dy = abs(c1 - c2);
    if (dx == 0 && dy == 0) {
        cout << 0 << endl;
        return;
    }
    if (dx + dy <= 3 || dx == dy) {
        cout << 1 << endl;
        return;
    }
    if (dx + dy <= 6 || (dx + dy) % 2 == 0 || abs(dx - dy) <= 3) {
        cout << 2 << endl;
        return;
    }
    cout << 3 << endl;
}

int main() {
    solve();
    return 0;
}

