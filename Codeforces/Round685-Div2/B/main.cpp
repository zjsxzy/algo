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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        bool flag = false;
        for (int i = 0; i < l; i++) {
            if (s[i] == s[l]) {
                flag = true;
                break;
            }
        }
        for (int i = r + 1; i < n; i++) {
            if (s[i] == s[r]) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

