/*
ID: frankzh1
TASK: hidden
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int min_express(string& sec) {
    int n = sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (sec[(i + k) % n] == sec[(j + k) % n]) {
            k++;
        } else {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    return min(i, j);
}

void solve() {
    int n;
    cin >> n;
    string str, s;
    while (cin >> s) {
        str += s;
    }
    cout << min_express(str) << endl;
}

int main() {
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    solve();
    return 0;
}

