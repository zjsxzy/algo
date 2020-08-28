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
typedef unsigned long long LL;

int n, k;
vector<int> a;

int dig(LL n) {
    int res = 0;
    for (; n; n /= 10) res++;
    return res;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<LL> pw(11);
    pw[0] = 1;
    for (int i = 0; i < 10; i++) {
        pw[i + 1] = pw[i] * 10 % k;
    }
    map<LL, int> cnt[11];
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i][(LL)a[j] * pw[i] % k]++;
        }
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        LL x = a[i];
        LL mod = (k - x % k) % k;
        int d = dig(x);
        res += cnt[d][mod];
        if (((LL)x * pw[d] + x) % k == 0) res--;
        // cout << a[i] << " " << cnt[d][mod] << endl;
    }
    cout << res << endl;
    return 0;
}
