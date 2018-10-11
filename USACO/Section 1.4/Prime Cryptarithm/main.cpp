/*
ID: frankzh1
TASK: crypt1
LANG: C++
 */
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

int n;
bool p[15];

bool f(int n) {
    while (n) {
        if (!p[n % 10]) {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool check(int x, int y) {
    int a = x * (y % 10), b = x * (y / 10), test = x * y;
    if (a > 999 || b > 999 || test > 9999) {
        return false;
    }
    if (f(a) && f(b) && f(x) && f(y) && f(test)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = true;
    }
    int res = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 10; j < 100; j++) {
            if (check(i, j)) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}

