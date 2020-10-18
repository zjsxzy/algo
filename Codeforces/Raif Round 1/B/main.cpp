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

const int MAXN = 300005;
int v[MAXN];
int n;
string path;

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        memset(v, 0, sizeof(v));
        cin >> n;
        cin >> path;
        int res = 0;
        map<char, int> cnt;
        set<int> st;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cnt[path[i]]++;
            if (path[i] == '-') {
                v[i] = 1;
                v[(i + 1) % n] = 1;
            }
        }
        if (cnt['>'] + cnt['-'] == n || cnt['<'] + cnt['-'] == n) cout << n << endl;
        else {
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += (v[i] == 1);
            }
            cout << res << endl;
        }
    }
    return 0;
}

