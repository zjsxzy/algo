/*
ID: frankzh1
TASK: frac1
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n;
    cin >> n;
    set<pair<int, int>> st;
    st.insert({0, 1});
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int g = gcd(i, j);
            int a = i / g, b = j / g;
            st.insert({a, b});
        }
    }
    st.insert({1, 1});
    vector<pair<int, int>> res;
    for (auto &x: st) {
        res.emplace_back(x);
    }
    sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
            return a.first * b.second < a.second * b.first;
    });
    for (auto &p: res) {
        cout << p.first << "/" << p.second << endl;
    }
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    solve();
    return 0;
}

