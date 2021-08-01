/*
ID: frankzh1
TASK: sprime
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool isprime(int x) {
    if (x % 2 == 0) return false;
    int q = sqrt(x);
    for (int i = 3; i <= q; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> first{2, 3, 5, 7};
    vector<int> other{1, 3, 7, 9};
    vector<int> q;
    for (auto &x: first) {
        q.emplace_back(x);
    }
    for (int i = 2; i <= n; i++) {
        vector<int> newq;
        for (auto &num: q) {
            for (auto &x: other) {
                int t = num * 10 + x;
                if (isprime(t)) {
                    newq.emplace_back(t);
                }
            }
        }
        q = newq;
    }
    for (auto &x: q) {
        cout << x << endl;
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    solve();
    return 0;
}

