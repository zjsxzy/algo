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

const int MAXN = 105;
int a, b, c;
double prob[MAXN][MAXN][MAXN];

void solve() {
    cin >> a >> b >> c;
    memset(prob, 0, sizeof(prob));
    prob[a][b][c] = 1;
    for (int i = a; i < 100; i++) {
        for (int j = b; j < 100; j++) {
            for (int k = c; k < 100; k++) {
                if (prob[i][j][k] != 0) {
                    prob[i + 1][j][k] += prob[i][j][k] * i / (i + j + k);
                    prob[i][j + 1][k] += prob[i][j][k] * j / (i + j + k);
                    prob[i][j][k + 1] += prob[i][j][k] * k / (i + j + k);
                }
            }
        }
    }
    double res = 0;
    for (int j = b; j < 100; j++) {
        for (int k = c; k < 100; k++) {
            res += (100 + j + k - a - b - c) * prob[100][j][k];
        }
    }
    for (int i = a; i < 100; i++) {
        for (int k = c; k < 100; k++) {
            res += (100 + i + k - a - b - c) * prob[i][100][k];
        }
    }
    for (int i = a; i < 100; i++) {
        for (int j = b; j < 100; j++) {
            res += (100 + i + j - a - b - c) * prob[i][j][100];
        }
    }
    printf("%.6f\n", res);
}

int main() {
    solve();
    return 0;
}

