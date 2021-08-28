/*
ID: frankzh1
TASK: palsquare
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

char int2char(int x) {
    if (x < 10) return x + '0';
    else return x - 10 + 'A';
}

string convert(int n, int B) {
    string res = "";
    for (; n; n /= B) {
        int x = n % B;
        res += int2char(x);
    }
    reverse(res.begin(), res.end());
    return res;
}

bool check(int n, int B) {
    string num = convert(n, B);
    int len = (int)num.size();
    for (int i = 0; i < (len >> 1); i++) {
        if (num[i] != num[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int B;
    cin >> B;
    for (int i = 1; i <= 300; i++) {
        int sq = i * i;
        if (check(i * i, B)) {
            cout << convert(i, B) << " " << convert(i * i, B) << endl;
        }
    }
    return 0;
}

