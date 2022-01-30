#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void big(LL x, LL y) {
    map<LL, int> step;
    step[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        LL t = q.front(); q.pop();
        int d = step[t];
        if (t == y) {
            cout << d << endl;
            return;
        }
        if (step.find(t + 1) == step.end()) {
            step[t + 1] = d + 1;
            q.push(t + 1);
        }
        if (t * 2 <= y && step.find(t * 2) == step.end()) {
            step[t * 2] = d + 1;
            q.push(t * 2);
        }
    }
}

void small(LL x, LL y) {
    map<LL, int> step;
    step[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        LL t = q.front(); q.pop();
        int d = step[t];
        if (t == y) {
            cout << d << endl;
            return;
        }
        if (step.find(t + 1) == step.end()) {
            step[t + 1] = d + 1;
            q.push(t + 1);
        }
        if (t % 2 == 0 && step.find(t / 2) == step.end()) {
            step[t / 2] = d + 1;
            q.push(t / 2);
        }
    }
}

void solve() {
    LL x, y;
    LL cnt = 0;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl;
        return;
    } else if (x < y) {
        big(x, y);
    } else {
        small(x, y);
    }
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

