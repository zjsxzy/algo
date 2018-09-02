/*
ID: frankzh1
TASK: transform
LANG: C++
*/
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

struct matrix {
    int n;
    vector<vector<char> > arr;

    matrix(int n) {
        this->n = n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(n);
        }
    }

    void read() {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                arr[i][j] = s[j];
            }
        }
    }

    matrix rotate() {
        matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.arr[i][j] = arr[n - j - 1][i];
            }
        }
        return res;
    }

    matrix reflex() {
        matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.arr[i][j] = arr[i][n - j - 1];
            }
        }
        return res;
    }

    bool same(const matrix &other) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != other.arr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n;
    cin >> n;
    matrix st(n), ed(n);
    st.read();
    ed.read();
    matrix cur = st;
    for (int i = 1; i <= 3; i++) {
        cur = cur.rotate();
        if (cur.same(ed)) {
            cout << i << endl;
            return 0;
        }
    }
    cur = st.reflex();
    if (cur.same(ed)) {
        cout << 4 << endl;
        return 0;
    }
    for (int i = 1; i <= 3; i++) {
        cur = cur.rotate();
        if (cur.same(ed)) {
            cout << 5 << endl;
            return 0;
        }
    }
    if (st.same(ed)) {
        cout << 6 << endl;
    } else {
        cout << 7 << endl;
    }
    return 0;
}

