/*
ID: frankzh1
TASK: ariprog
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> f(m * m * 2 + 1);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            f[i * i + j * j] = true;
        }
    }
    vector<int> vec;
    for (int x = 0; x <= m * m * 2; x++) {
        if (f[x]) vec.emplace_back(x);
    }
    sort(vec.begin(), vec.end());
    int sz = vec.size();
    vector<pair<int, int>> res;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            int a = vec[i], b = vec[j] - vec[i];
            bool flag = true;
            if (a + (n - 1) * b > m * m * 2) break;
            for (int k = 2; k < n; k++) {
                if (!f[a + k * b]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.emplace_back(a, b);
            }
        }
    }
    if (res.size() == 0) cout << "NONE" << endl;
    else {
        sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
                return a.second < b.second || (a.second == b.second && a.first < b.first);
        });
        for (auto &p: res) {
            cout << p.first << " " << p.second << endl;
        }
    }
}

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    solve();
    return 0;
}

