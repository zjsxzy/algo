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

const int MAXN = 200005;
int n;
LL a[MAXN], s[MAXN], m[MAXN];


int main() {
    cin >> n;
    s[0] = 0;
    m[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        m[i] = max(m[i - 1], s[i]);
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << m[i] << " ";
    cout << endl;
    */
    LL cur = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, cur + m[i]);
        cur += s[i];
    }
    cout << res << endl;
    return 0;
}
