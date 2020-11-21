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
string s;
char st[maxn];

int main() {
    cin >> n;
    cin >> s;
    int m = 0;
    for (int i = 0; i < n; i++) {
        st[m] = s[i];
        if (m >= 2 && st[m - 2] == 'f' && st[m - 1] == 'o' && st[m] == 'x') {
            m -= 2;
        } else {
            m++;
        }
    }
    cout << m << endl;
    return 0;
}

