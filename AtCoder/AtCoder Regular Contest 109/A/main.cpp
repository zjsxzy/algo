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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int n = 100;
    vector<vector<int>> d(2 * (n + 1), vector<int>(2 * (n + 1)));
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = i + 1; j <= 2 * n; j++) {
            d[i][j] = d[j][i] = 1000000;
        }
    }
    for (int i = 1; i < n; i++) {
        d[i][i + 1] = y;
        d[i + 1][i] = y;
        d[n + i][n + i + 1] = y;
        d[n + i + 1][n + i] = y;
    }
    for (int i = 1; i <= n; i++) {
        d[i][n + i] = d[n + i][i] = x;
    }
    for (int i = 2; i <= n; i++) {
        d[i][n + i - 1] = d[n + i - 1][i] = x;
    }
    for (int k = 1; k <= 2 * n; k++)
        for (int i = 1; i <= 2 * n; i++)
            for (int j = 1; j <= 2 * n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
    cout << d[a][n + b] << endl;
    return 0;
}

