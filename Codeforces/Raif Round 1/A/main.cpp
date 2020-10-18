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

int main() {
    int ts;
    int x1, y1, x2, y2;
    cin >> ts;
    while (ts--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2) {
            cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        } else {
            cout << abs(x1 - x2) + abs(y1 - y2) + 2 << endl;
        }
    }
    return 0;
}

