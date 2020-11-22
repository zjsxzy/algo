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
    LL k, d;
    cin >> d >> k;
    LL cur = 0;
    while ((cur + k) * (cur + k) * 2 <= d * d) {
        cur += k;
    }
    if ((cur + k) * (cur + k) + cur * cur <= d * d) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
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

