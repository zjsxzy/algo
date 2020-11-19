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

int main() {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            q.push(i);
        }
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') {
            if (q.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int x = q.front(); q.pop();
            while (x < i) {
                if (q.empty()) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    int y = q.front(); q.pop();
                    res += (LL)(y - x);
                }
                if (q.empty()) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    x = q.front(); q.pop();
                }
            }
            res += (LL)(x - i);
        }
    }
    cout << res << endl;
    return 0;
}

