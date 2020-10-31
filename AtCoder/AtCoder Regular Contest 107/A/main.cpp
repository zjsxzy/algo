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

const int mod = 998244353;

int main() {
    LL a, b, c;
    cin >> a >> b >> c;
    LL res = a * (a + 1) / 2 % mod;
    res = res * b % mod;
    res = res * (b + 1) / 2 % mod;
    res = res * c % mod;
    res = res * (c + 1) / 2 % mod;
    cout << res << endl;
    return 0;
}

