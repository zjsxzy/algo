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
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> mat(n);
    vector<int> res(10);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<int> min_row(10, -1);
    for (int i = 0; i < n; i++) {
        vector<int> min_col(10, -1), max_col(10, -1);
        for (int j = 0; j < n; j++) {
            int c = mat[i][j] - '0';
            if (min_row[c] == -1) min_row[c] = i;
            if (min_col[c] == -1) min_col[c] = j;
            max_col[c] = j;
        }
        for (int k = 0; k < 10; k++) {
            if (min_row[k] != -1) {
                int t;
                if (min_col[k] != -1) {
                    t = (i - min_row[k]) * (n - 1 - min_col[k]);
                    res[k] = max(res[k], t);
                }
                if (max_col[k] != -1) {
                    t = (i - min_row[k]) * max_col[k];
                    res[k] = max(res[k], t);
                }
            }
        }
    }
    vector<int> min_col(10, -1);
    for (int j = 0; j < n; j++) {
        vector<int> mn_row(10, -1), mx_row(10, -1);
        for (int i = 0; i < n; i++) {
            int c = mat[i][j] - '0';
            if (mn_row[c] == -1) mn_row[c] = i;
            if (min_col[c] == -1) min_col[c] = j;
            mx_row[c] = j;
        }
        for (int k = 0; k < 10; k++) {
            if (min_col[k] != -1) {
                int t;
                if (mn_row[k] != -1) {
                    t = (j - min_col[k]) * (n - 1 - mn_row[k]);
                    res[k] = max(res[k], t);
                }
                if (mx_row[k] != -1) {
                    t = (j - min_col[k]) * mx_row[k];
                    res[k] = max(res[k], t);
                }
            }
        }
    }
    for (int k = 0; k < 10; k++) {
        cout << res[k] << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

