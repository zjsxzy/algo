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

int a[4];
bool flag;
int sum;

void solve(int idx, int cur) {
    if (idx == 4) return;
    if (cur == sum - cur) {
        flag = true;
        return;
    }
    solve(idx + 1, cur);
    solve(idx + 1, cur + a[idx]);
}

int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sum = a[0] + a[1] + a[2] + a[3];
    flag = false;
    solve(0, 0);
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
