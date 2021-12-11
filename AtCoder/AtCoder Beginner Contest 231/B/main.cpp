#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    while (n--) {
        string name;
        cin >> name;
        cnt[name]++;
    }
    string res;
    int mx = 0;
    for (auto& [k, v]: cnt) {
        if (v > mx) {
            mx = v;
            res = k;
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

