#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (n % 2 == 1) {
        cout << B[n / 2] - A[n / 2] + 1 << endl;
    } else {
        cout << B[n / 2 - 1] + B[n / 2] - A[n / 2 - 1] - A[n / 2] + 1 << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

