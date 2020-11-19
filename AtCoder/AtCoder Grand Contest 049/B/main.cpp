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
    vector<int> vec;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') vec.push_back(i);
        if (s[i] == '1') {
            if (vec.empty()) {
                vec.push_back(i);
            } else {
                int pre = vec.back();
                vec.pop_back();
                res += i - pre;
            }
        }
    }
    if (!vec.empty()) res = -1;
    cout << res << endl;
    return 0;
}

