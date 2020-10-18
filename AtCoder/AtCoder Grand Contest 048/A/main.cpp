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

const string t = "atcoder";
string s;
int n;
bool flag;

void solve() {
    int i = 0;
    while (s[i] == 'a') {
        i++;
    }
    if (i == n) {
        cout << -1 << endl;
        return;
    }
    for (int j = i; j > 1; j--) {
        swap(s[j], s[j - 1]);
    }
    // cout << i << " " << s << endl;
    if (s > "atcoder") {
        cout << max(0, i - 1) << endl;
    } else {
        cout << i << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        flag = false;
        cin >> s;
        n = s.size();
        solve();
    }
    return 0;
}

