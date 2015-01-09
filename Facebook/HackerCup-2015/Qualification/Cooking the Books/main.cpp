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

LL vec2num(vector<int> &dig) {
    LL ret = 0;
    for (int i = 0; i < dig.size(); i++) {
        ret = ret * 10 + dig[i];
    }
    return ret;
}

void solve(LL N) {
    vector<int> dig;
    LL x = N, numZero = 0;
    for (; x; x /= 10) {
        dig.PB(x % 10);
    }
    reverse(dig.begin(), dig.end());
    LL Min = vec2num(dig), Max = vec2num(dig);
    for (int i = 0; i < dig.size(); i++) {
        for (int j = i + 1; j < dig.size(); j++) {
            swap(dig[i], dig[j]);
            if (dig[0] != 0) {
                Min = min(Min, vec2num(dig));
                Max = max(Max, vec2num(dig));
            }
            swap(dig[i], dig[j]);
        }
    }
    cout << Min << " " << Max << endl;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        LL N;
        cin >> N;
        solve(N);
    }
	return 0;
}

