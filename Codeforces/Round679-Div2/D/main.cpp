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

const int MAXN = 200005;
int n;
int buy[MAXN];
string op[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> op[i];
        if (op[i] == "-") {
            cin >> buy[i];
        }
    }

    int tot = 0;
    vector<int> stk, res(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (op[i] == "+") {
            tot++;
            stk.push_back(i);
        } else {
            tot--;
            if (tot < 0) {
                cout << "NO" << endl;
                return 0;
            }
            int top = stk.back(); stk.pop_back();
            res[top] = buy[i];
        }
    }

    priority_queue<int> pq;
    for (int i = 0; i < 2 * n; i++) {
        if (op[i] == "+") {
            pq.push(-res[i]);
        } else {
            int b = -pq.top(); pq.pop();
            if (b != buy[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < 2 * n; i++) {
        if (op[i] == "+") {
            cout << res[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

