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

const int MAXN = 505;
int n, m;

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        cin >> n >> m;
        vector<vector<int> > row(n), col(m);
        map<int, int> order;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                row[i].push_back(x);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                order[row[i][j]] = i;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                col[j].push_back(x);
            }
        }

        for (auto it : col[0]) {
            for (auto x : row[order[it]]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

