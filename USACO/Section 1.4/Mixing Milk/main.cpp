/*
ID: frankzh1
TASK: milk
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

int n, m;
vector<pair<int, int> > farmer;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int p, a;
        cin >> p >> a;
        farmer.PB(MP(p, a));
    }
    sort(farmer.begin(), farmer.end());
    int sum = 0, cost = 0;
    for (vector<pair<int, int> >::iterator it = farmer.begin();
            it != farmer.end(); it++) {
        if (sum + it->second <= n) {
            sum += it->second;
            cost += it->first * it->second;
        } else {
            cost += it->first * (n - sum);
            break;
        }
    }
    cout << cost << endl;
    return 0;
}

