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
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<int> min_row(10, -1), max_row(10, -1), min_col(10, -1), max_col(10, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = mat[i][j] - '0';
            if (min_row[t] == -1) min_row[t] = i;
            else min_row[t] = min(min_row[t], i);
            if (min_col[t] == -1) min_col[t] = j;
            else min_col[t] = min(min_col[t], j);
            max_row[t] = max(max_row[t], i);
            max_col[t] = max(max_col[t], j);
        }
    }

    vector<int> res(10);
    // by row
    for (int i = 0; i < n; i++) {
        map<int, vector<int>> vec;
        for (int j = 0; j < n; j++) {
            vec[mat[i][j] - '0'].push_back(j);
        }
        for (int k = 0; k < 10; k++) {
            if (vec[k].size() >= 1) {
                int width = max(vec[k][vec[k].size() - 1], n - 1 - vec[k][0]);
                int height = max(i - min_row[k], max_row[k] - i);
                res[k] = max(res[k], width * height);
                if (vec[k].size() > 1) {
                    width = vec[k][vec[k].size() - 1] - vec[k][0];
                    height = max(i, n - 1 - i);
                    res[k] = max(res[k], width * height);
                }
            }
        }
    }
    // by col
    for (int j = 0; j < n; j++) {
        map<int, vector<int>> vec;
        for (int i = 0; i < n; i++) {
            vec[mat[i][j] - '0'].push_back(i);
        }
        for (int k = 0; k < 10; k++) {
            if (vec[k].size() >= 1) {
                int width = max(vec[k][vec[k].size() - 1], n - 1 - vec[k][0]);
                int height = max(j - min_col[k], max_col[k] - j);
                res[k] = max(res[k], width * height);
                if (vec[k].size() > 1) {
                    width = vec[k][vec[k].size() - 1] - vec[k][0];
                    height = max(j, n - 1 - j);
                    res[k] = max(res[k], width * height);
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

