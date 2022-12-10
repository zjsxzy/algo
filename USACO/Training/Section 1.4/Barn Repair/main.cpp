/*
ID: frankzh1
TASK: barn1
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

int m, s, c;
vector<int> num, diff;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    cin >> m >> s >> c;
    num.resize(c);
    for (int i = 0; i < c; i++) {
        cin >> num[i];
    }
    if (m > c) {
        cout << c << endl;
        return 0;
    }
    sort(num.begin(), num.end());
    int res = num[c - 1] - num[0] + 1;
    for (int i = 0; i < c - 1; i++) {
        diff.push_back(num[i + 1] - num[i] - 1);
    }
    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());
    for (int i = 0; i < m - 1; i++) {
        res -= diff[i];
    }
    cout << res << endl;
    return 0;
}
