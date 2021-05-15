#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

string p;

bool check(int x) {
    vector<int> cnt(10);
    int j = 4;
    for (; x; x /= 10) {
        cnt[x % 10]++;
        j--;
    }
    for (int i = 0; i < j; i++) {
        cnt[0]++;
    }
    for (int i = 0; i < 10; i++) {
        if (p[i] == 'o' && cnt[i] == 0) return false;
        if (p[i] == 'x' && cnt[i] > 0) return false;
    }
    return true;
}

void solve() {
    cin >> p;
    int res = 0;
    for (int i = 0; i <= 9999; i++) {
        if (check(i)) res++;
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

