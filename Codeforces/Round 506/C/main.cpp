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
vector<pair<int, int> > v;
multiset<int> l, r;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        l.insert(v[i].first);
        r.insert(v[i].second);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        l.erase(l.find(v[i].first));
        r.erase(r.find(v[i].second));
        int val = *r.begin() - *(--l.end());
        res = max(res, val);
        l.insert(v[i].first);
        r.insert(v[i].second);
    }
    cout << res << endl;
    return 0;
}
