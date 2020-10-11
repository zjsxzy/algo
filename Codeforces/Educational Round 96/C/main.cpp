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

void solve(int n) {
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(i);
    }
    vector<pair<int, int> > res;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if (pq.empty()) {
            cout << a << endl;
            break;
        }
        int b = pq.top();
        pq.pop();
        if ((a + b) % 2 == 0) {
            pq.push((a + b) / 2);
        } else {
            pq.push((a + b) / 2 + 1);
        }
        res.push_back(make_pair(b, a));
    }
    for (auto it:res) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

