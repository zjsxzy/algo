#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < 2 * r + 1; i++) {
        if (i == 0) {
            cout << "..";
            for (int j = 0; j < c - 1; j++) {
                cout << "+-";
            }
            cout << "+" << endl;
        } else if (i == 1) {
            cout << "..";
            for (int j = 0; j < c - 1; j++) {
                cout << "|.";
            }
            cout << "|" << endl;
        } else {
            if (i % 2 == 0) {
                for (int j = 0; j < c; j++) {
                    cout << "+-";
                }
                cout << "+" << endl;
            } else {
                for (int j = 0; j < c; j++) {
                    cout << "|.";
                }
                cout << "|" << endl;
            }
        }
    }
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        printf("Case #%d:\n", cs);
        solve();
    }
    return 0;
}

