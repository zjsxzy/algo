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

const int MAXN = 1505;
int h, w;
int n, m;
int mat[MAXN][MAXN];

int main() {
    memset(mat, 0, sizeof(mat));
    cin >> h >> w >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 2;
    }
    for (int i = 1; i <= h; i++) {
        bool ill = false;
        for (int j = 1; j <= w; j++) {
            if (mat[i][j] == 0) {
                if (ill) {
                    mat[i][j] = -1;
                }
            } else if (mat[i][j] == 1) {
                ill = true;
            } else if (mat[i][j] == 2) {
                ill = false;
            }
        }

        ill = false;
        for (int j = w; j >= 1; j--) {
            if (mat[i][j] == 0) {
                if (ill) {
                    mat[i][j] = -1;
                }
            } else if (mat[i][j] == 1) {
                ill = true;
            } else if (mat[i][j] == 2) {
                ill = false;
            }
        }
    }

    for (int j = 1; j <= w; j++) {
        bool ill = false;
        for (int i = 1; i <= h; i++) {
            if (mat[i][j] == 0) {
                if (ill) {
                    mat[i][j] = -1;
                }
            } else if (mat[i][j] == 1) {
                ill = true;
            } else if (mat[i][j] == 2) {
                ill = false;
            }
        }

        ill = false;
        for (int i = h; i >= 1; i--) {
            if (mat[i][j] == 0) {
                if (ill) {
                    mat[i][j] = -1;
                }
            } else if (mat[i][j] == 1) {
                ill = true;
            } else if (mat[i][j] == 2) {
                ill = false;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (mat[i][j] == 1 || mat[i][j] == -1) {
                //cout << i << " " << j << endl;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
