#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int rs, rh;
    cin >> rs >> rh;
    int n, m;
    cin >> n;
    vector<int> x(n), y(n), red(n);
    auto dist = [&](int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        red[i] = dist(x[i], y[i], 0, 0);
    }
    cin >> m;
    vector<int> z(m), w(m), yellow(m);
    for (int i = 0; i < m; i++) {
        cin >> z[i] >> w[i];
        yellow[i] = dist(z[i], w[i], 0, 0);
    }
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if (red[i] <= (rs + rh) * (rs + rh)) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (yellow[j] < red[i]) {
                    flag = false;
                    break;
                }
            }
            s1 += flag;
        }
    }
    for (int i = 0; i < m; i++) {
        if (yellow[i] <= (rs + rh) * (rs + rh)) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (red[j] < yellow[i]) {
                    flag = false;
                    break;
                }
            }
            s2 += flag;
        }
    }
    cout << s1 << ' ' << s2 << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

