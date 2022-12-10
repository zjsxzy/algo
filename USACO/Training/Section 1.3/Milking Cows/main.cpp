/*
ID: frankzh1
TASK: milk2
LANG: C++
 */
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

int n;
multiset<pair<int, int> > milk;

pair<int, int> cover() {
    multiset<pair<int, int> >::iterator it = milk.begin();
    int sum = 1, st = it->first, ed = 0, res1 = 0, res2 = 0;
    it++;
    for (; it != milk.end(); it++) {
        if (it->second == 0) { // left
            if (sum == 0) {
                res2 = max(res2, it->first - ed);
                st = it->first;
            }
            sum++;
        } else if (it->second == 1){ // right
            sum--;
            if (sum == 0) {
                res1 = max(res1, it->first - st);
                ed = it->first;
            }
        }
    }
    return MP(res1, res2);
}

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        milk.insert(MP(l, 0));
        milk.insert(MP(r, 1));
    }

    pair<int, int> res = cover();
    cout << res.first << " " << res.second << endl;
    return 0;
}

