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


void solve(int n) {
    for (int i = 0; 3 * i <= n; i++) {
        for (int j = 0; 3 * i + 5 * j <= n; j++) {
            for (int k = 0; 3 * i + 5 * j + 7 * k <= n; k++) {
                if (3 * i + 5 * j + 7 * k == n) {
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

