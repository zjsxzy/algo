/*
ID: frankzh1
TASK: sort3
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), s(4);
    for (auto &x: a) {
        cin >> x;
        s[x]++;
    }
    int p2 = s[1], p3 = n - 1, res = 0;
    for (int i = 0; i < s[1]; i++) {
        if (a[i] == 2) {
            while (a[p2] != 1) p2++;
            int tmp = a[i];
            a[i] = a[p2];
            a[p2] = tmp;
            res++;
        } else if (a[i] == 3) {
            while (a[p3] != 1) p3--;
            int tmp = a[i];
            a[i] = a[p3];
            a[p3] = tmp;
            res++;
        }
    }
    for (int i = s[1]; i < s[1] + s[2]; i++) {
        if (a[i] == 3) res++;
    }
    cout << res << endl;
}

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    solve();
    return 0;
}

