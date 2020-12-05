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
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    LL n;
    cin >> n;
    string t;
    cin >> t;

    LL l = 1e10;
    if (n < 3) {
        if (n == 1) {
            if (t == "1") {
                cout << 2 * l << endl;
            } else if (t == "0") {
                cout << l << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (n == 2) {
            if (t == "10" || t == "11") {
                cout << l << endl;
            } else if (t == "01") {
                cout << l - 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        return 0;
    }
    LL res = l * 3 + 1 - n, flag = true;
    for (int i = 0; i < n; i++) {
        if (t[i] != t[i % 3]) {
            flag = false;
        }
    }
    if (!flag) {
        cout << 0 << endl;
        return 0;
    }
    if (t.substr(0, 3) == "110") {
        cout << (res - 1) / 3 + 1 << endl;
    } else if (t.substr(0, 3) == "101") {
        cout << (res - 2) / 3 + 1 << endl;
    } else if (t.substr(0, 3) == "011") {
        cout << (res - 3) / 3 + 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

