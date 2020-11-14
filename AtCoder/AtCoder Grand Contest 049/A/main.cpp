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

const int maxn = 105;
int n;
bool vis[maxn];
int e[maxn][maxn];


void solve() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (e[i][k] && e[k][j]) {
                    e[i][j] = 1;
                }
    double res = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (e[j][i]) sum++;
        }
        res += 1.0 / sum;
    }
    printf("%.9f\n", (double)res);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        e[i][i] = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                e[i][j] = 1;
            }
        }
    }
    solve();
    return 0;
}

