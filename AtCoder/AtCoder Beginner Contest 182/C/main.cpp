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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        cnt[x % 3]++;
    }
    int a = cnt[1], b = cnt[2];
    int res = -1;
    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            if ((i + j * 2) % 3 == 0) {
                int temp = a - i + b - j;
                if (res == -1 || temp < res) {
                    res = temp;
                }
            }
        }
    }
    if (res == n) res = -1;
    cout << res << endl;
    return 0;
}

