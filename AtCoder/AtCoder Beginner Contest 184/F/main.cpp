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
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 45;
LL n, T;
LL a[MAXN];

set<LL> get_sum(vector<int> &num) {
    set<LL> ret;
    for (int i = 0; i < (1 << num.size()); i++) {
        LL sum = 0;
        for (int j = 0; j < num.size(); j++) {
            if (i & (1 << j)) {
                sum += num[j];
            }
        }
        ret.insert(sum);
    }
    return ret;
}

void solve() {
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> A, B;
    for (int i = 0; i < n / 2; i++) {
        A.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++) {
        B.push_back(a[i]);
    }
    set<LL> X = get_sum(A), Y = get_sum(B);

    LL res = 0;
    for (auto x : X) {
        auto it = Y.upper_bound(T - x);
        if (it == Y.begin()) continue;
        it--;
        res = max(res, x + *it);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

