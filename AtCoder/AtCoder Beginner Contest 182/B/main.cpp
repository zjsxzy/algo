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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = -1, mx = 0;
    for (int i = 2; i <= 1000; i++) {
        int tot = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) {
                tot++;
            }
        }
        if (tot > mx) {
            res = i;
            mx = tot;
        }
    }
    cout << res << endl;
    return 0;
}
