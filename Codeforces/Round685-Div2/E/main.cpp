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

const int AND_OP = 0;
const int OR_OP = 1;
const int XOR_OP = 2;

int query(int oper, int i, int j) {
    if (oper == OR_OP) cout << "OR ";
    if (oper == AND_OP) cout << "AND ";
    if (oper == XOR_OP) cout << "XOR ";
    cout << i << " " << j << endl;
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret;
}

const int MAXN = 1 << 17;
int n;
int a[MAXN], v[MAXN], from[MAXN];

void output() {
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    fflush(stdout);
}

void case1(int i, int j) {
    a[i] = a[j] = query(AND_OP, i, j);
    a[1] = v[i] ^ a[i];
    for (int k = 2; k <= n; k++) {
        a[k] = a[1] ^ v[k];
    }
    output();
}

int get_bit(int x, int b) {
    return (x >> b) & 1;
}

void case2(int i, int j) {
    int v1 = query(AND_OP, 1, i);
    int v2 = query(AND_OP, 1, j);
    for(int b = 0; b < 16; b++) {
        int me = 0;
        if (b == 0) {
            me = get_bit(v2, b);
        } else {
            me = get_bit(v1, b);
        }
        a[1] |= me << b;
    }
    for (int k = 2; k <= n; k++) {
        a[k] = a[1] ^ v[k];
    }
    output();
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        v[i] = query(XOR_OP, 1, i);
    }
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            case1(1, i);
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (from[v[i]] == 0) {
            from[v[i]] = i;
        } else {
            case1(i, from[v[i]]);
            return;
        }
    }
    case2(from[1], from[2]);
}

int main() {
    solve();
    return 0;
}

