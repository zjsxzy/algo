#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int A, B;
bool check(int k) {
    int l = A / k + (A % k != 0);
    int r = B / k;
    return r - l >= 1;
}
void solve() {
    cin >> A >> B;
    for (int i = B; i >= 1; i--) {
        if (check(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

