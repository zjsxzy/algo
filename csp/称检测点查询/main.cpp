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
    int n, X, Y;
    cin >> n >> X >> Y;
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int d = (x - X) * (x - X) + (y - Y) * (y - Y);
        vec.push_back({d, i + 1});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < 3; i++) {
        cout << vec[i].second << endl;
    }
    return 0;
}

