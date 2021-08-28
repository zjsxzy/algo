/*
ID: frankzh1
TASK: wormhole
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 15;
int n, res;
int x[MAXN], y[MAXN];
int next_on_right[MAXN], partner[MAXN];

bool cycle() {
    /*
    for (int i = 0; i < n; i++) {
        cout << i << " " << partner[i] << endl;
    }
    cout << endl;
    */
    for (int start = 0; start < n; start++) {
        int pos = start;
        for (int count = 0; count < n; count++) {
            pos = next_on_right[partner[pos]];
            if (pos == -1) break;
        }
        if (pos != -1) return true;
    }
    return false;
}

void search() {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        if (partner[i] == -1) break;
    }

    if (i == n) {
        if (cycle()) res++;
    }

    for (int j = i + 1; j < n; j++) {
        if (partner[j] == -1) {
            partner[i] = j;
            partner[j] = i;
            search();
            partner[i] = partner[j] = -1;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    memset(next_on_right, -1, sizeof(next_on_right));
    memset(partner, -1, sizeof(partner));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (x[j] > x[i] && y[j] == y[i]) {
                if (next_on_right[i] == -1 || (x[j] - x[i] < x[next_on_right[i]] - x[i])) {
                    next_on_right[i] = j;
                }
            }
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cout << i << " " << next_on_right[i] << endl;
    }
    */

    // int res = search();
    res = 0;
    search();
    cout << res << endl;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    solve();
    return 0;
}

