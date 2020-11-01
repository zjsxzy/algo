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

const int MAXN = 200005;
int n, m;

int main() {
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    LL res = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        LL sum = 0;
        h.insert(x);
        for (multiset<int>::iterator it = h.begin(); it != h.end(); it++) {
            LL pre = *it;
            it++;
            LL nxt = *it;
            sum += nxt - pre;
        }
        auto it = h.find(x);
        if (it != h.end()) {
            h.erase(it);
        }
        if (res == -1 || sum < res) res = sum;
    }
    cout << res << endl;
    return 0;
}

