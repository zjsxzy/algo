#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve(int cs) {
    string n;
    cin >> n;
    int sum = 0;
    for (auto c: n) {
        sum += c - '0';
        sum %= 9;
    }
    printf("Case #%d: ", cs);
    int sz = n.size();
    if (sum == 0) {
        cout << n[0] << 0 << n.substr(1, sz - 1) << endl;
    } else {
        int r = 9 - sum;
        for (int i = 0; i < sz; i++) {
            if (n[i] - '0' > r) {
                cout << n.substr(0, i);
                cout << r;
                cout << n.substr(i, sz - i) << endl;
                return;
            }
        }
        cout << n << r << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        solve(cs);
    }
    return 0;
}

