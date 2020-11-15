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

const int maxn = 200005;
int n;
LL w;
LL plan[maxn];

int main() {
    cin >> n >> w;
    memset(plan, 0, sizeof(plan));
    LL mx = 0;
    for (int i = 0; i < n; i++) {
        LL s, t, p;
        cin >> s >> t >> p;
        plan[s] += p;
        plan[t] -= p;
        mx = max(mx, t);
    }
    for (int i = 0; i <= mx; i++) {
        if (i > 0)
            plan[i] += plan[i - 1];
        if (plan[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

