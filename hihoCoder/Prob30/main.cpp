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

const int MAXN = 100000 + 5;
int n;
int a[MAXN];
bool check(vector<int> &vec) {
    for (int i = 1; i <= n - 1; i++) {
        if (i == 1) {
            vec[2] = a[1] - vec[1];
        } else {
            vec[i + 1] = a[i] - vec[i - 1] - vec[i];
        }
        if (vec[i + 1] < 0 || vec[i + 1] > 1) return false;
    }
    return vec[n - 1] + vec[n] == a[n];
}
vector<int> solve() {
    vector<int> x(n + 1), y(n + 1);
    x[1] = 0;
    bool flagX = check(x);
    y[1] = 1;
    bool flagY = check(y);
    if (flagX && flagY) {
        for (int i = 1; i <= n; i++)
            if (x[i] != y[i]) x[i] = -1;
        return x;
    } else if (flagX && !flagY) {
        return x;
    } else if (!flagX && flagY) {
        return y;
    }
	return x;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> ans = solve();
        vector<int> pos1, pos0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 1) pos1.PB(i);
            else if (ans[i] == 0) pos0.PB(i);
        }
        cout << pos1.size();
        for (int i = 0; i < pos1.size(); i++)
            cout << " " << pos1[i];
		cout << endl;
        cout << pos0.size();
        for (int i = 0; i < pos0.size(); i++)
            cout << " " << pos0[i];
		cout << endl;
    }
	return 0;
}

