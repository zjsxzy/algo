#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    auto query = [&](int A, int B, int C, int D) {
        cout << "? " << A << ' ' << B << ' ' << C << ' ' << D << endl;
        fflush(stdout);
        int x;
        cin >> x;
        return x;
    };

    auto find = [&](int row) {
        int lo = 1, hi = n, res;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1, x;
            if (row) {
                x = query(lo, mid, 1, n);
            } else {
                x = query(1, n, lo, mid);
            }
            if (x < mid - lo + 1) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    int r, c;
    r = find(1);
    c = find(0);
    cout << "! " << r << ' ' << c << endl;
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

