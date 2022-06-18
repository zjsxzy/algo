#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int A[5][5];
void solve() {
    vector<int> h(3);
    for (auto& x: h) cin >> x;
    vector<int> w(3);
    for (auto& x: w) cin >> x;
    int res = 0;
    for (int a = 1; a < h[0]; a++) {
        A[0][0] = a;
        for (int b = 1; b < h[0]; b++) {
            A[0][1] = b;
            if (a + b >= h[0]) continue;
            for (int c = 1; c < h[1]; c++) {
                A[1][0] = c;
                if (a + c >= w[0]) continue;
                for (int d = 1; d < h[1]; d++) {
                    A[1][1] = d;
                    if (c + d >= h[1]) continue;
                    if (b + d >= w[1]) continue;

                    for (int i = 0; i < 2; i++) {
                        A[i][2] = h[i] - A[i][0] - A[i][1];
                        A[2][i] = w[i] - A[0][i] - A[1][i];
                    }
                    if (A[2][0] + A[2][1] >= h[2]) continue;
                    if (A[0][2] + A[1][2] >= w[2]) continue;
                    if (h[2] - A[2][0] - A[2][1] == w[2] - A[0][2] - A[1][2]) {
                        res++;
                    }
                }
            }
        }
    }
    cout << res << endl;
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

