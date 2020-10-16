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

string s;
int n, k;

int main() {
    cin >> n >> k;
    cin >> s;
    int pos = -1;
    for (int i = 1; i < n; i++) {
        if (s.substr(i, n - i) == s.substr(0, n - i)) {
            //cout << s.substr(i, n - i) << " " << s.substr(0, n - i) << endl;
            pos = i;
            break;
        }
    }
    string pre, suf;
    if (pos != -1) {
        pre = s.substr(0, pos);
        suf = s.substr(pos, n - pos);
    } else {
        pre = s;
        suf = "";
    }
    for (int i = 0; i < k; i++) {
        cout << pre;
    }
    cout << suf << endl;
    return 0;
}
