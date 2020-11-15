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

int n, k;
int t[10][10];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }

    vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }
    int res = 0;
    do {
        if (perm[0] != 0) {
            break;
        }
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += t[perm[i - 1]][perm[i]];
        }
        sum += t[perm[n - 1]][0];
        if (sum == k) res++;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << res << endl;
    return 0;
}

