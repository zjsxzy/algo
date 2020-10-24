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

int n, m;
const int MAXR = 100000000;

int main() {
    cin >> n >> m;
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            cout << 2 * i - 1 << " " << 2 * i << endl;
        }
        return 0;
    }
    if (m < 0 || m >= n - 1) {
        cout << -1 << endl;
        return 0;
    }
    int i = 1;
    cout << 1 << " " << MAXR << endl;
    for (i = 2; i <= m + 2; i++) {
        cout << 2 * i - 1 << " " << 2 * i << endl;
    }
    for (; i <= n; i++) {
        cout << MAXR + 2 * i - 1 << " " << MAXR + 2 * i << endl;
    }
    return 0;
}

