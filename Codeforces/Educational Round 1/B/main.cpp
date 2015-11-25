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


string shift(string &str, int k) {
    int n = str.size();
    k %= n;
    return str.substr(n - k, k) + str.substr(0, n - k);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    string str;
    int n;
    cin >> str >> n;
    while (n--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        string sub = str.substr(l, r - l + 1);
        string newsub = shift(sub, k);
        str.replace(l, r - l + 1, newsub);
//        cout << str << endl;
    }
    cout << str << endl;
	return 0;
}

