/*
ID: frankzh1
TASK: msquare
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int n = 8;
vector<int> target;
map<vector<int>, string> seq;

void A(vector<int>& x) {
    for (int i = 0; i < 4; i++) {
        int temp = x[i];
        x[i] = x[7 - i];
        x[7 - i] = temp;
    }
}

void B(vector<int>& x) {
    vector<int> xx = x;
    x[0] = xx[3], x[1] = xx[0], x[2] = xx[1], x[3] = xx[2];
    x[4] = xx[5], x[5] = xx[6], x[6] = xx[7], x[7] = xx[4];
}

void C(vector<int> &x) {
    vector<int> xx = x;
    x[1] = xx[6], x[2] = xx[1], x[5] = xx[2], x[6] = xx[5];
}

void output(vector<int>& x) {
    for (auto &c: x) {
        cout << c << " ";
    }
    cout << endl;
}

void solve() {
    target.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }
    queue<vector<int>> q;
    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        start[i] = i + 1;
    }
    q.push(start);
    seq[start] = "";
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (x == target) {
            cout << seq[target].size() << endl;
            cout << seq[target] << endl;
            return;
        }
        vector<int> nxt = x;
        A(nxt);
        if (seq.find(nxt) == seq.end()) {
            q.push(nxt);
            seq[nxt] = seq[x] + 'A';
        }

        nxt = x;
        B(nxt);
        if (seq.find(nxt) == seq.end()) {
            q.push(nxt);
            seq[nxt] = seq[x] + 'B';
        }

        nxt = x;
        C(nxt);
        if (seq.find(nxt) == seq.end()) {
            q.push(nxt);
            seq[nxt] = seq[x] + 'C';
        }
    }
}

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    solve();
    return 0;
}

