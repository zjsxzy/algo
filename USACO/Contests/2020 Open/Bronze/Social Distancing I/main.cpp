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

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "1";
    vector<int> one, two;
    int res = INT_MAX, prev = -1;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '1') {
            int dis = i - prev;
            if (prev == -1 || i == n) {
                one.push_back(dis - 1);
                two.push_back((dis - 1) / 2);
            } else {
                res = min(res, dis);
                one.push_back(dis / 2);
                two.push_back(dis / 3);
            }
            prev = i;
        }
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    if (prev == n) { // no 1
        cout << n - 1 << endl;
        return 0;
    }
    int res2 = 0;
    if (two.size() > 0) {
        res2 = max(res2, two[two.size() - 1]);
    }
    if (one.size() > 1) {
        res2 = max(res2, one[one.size() - 2]);
    }
    if (res2 > 0) res = min(res, res2);
    cout << res << endl;
    return 0;
}

