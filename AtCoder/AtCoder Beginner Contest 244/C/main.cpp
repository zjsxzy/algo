#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int x;
    vector<int> vst(2 * n + 2);
    cout << 1 << endl;
    vst[1] = true;
    while (cin >> x) {
        if (x == 0) return;
        vst[x] = true;
        for (int i = 1; i <= 2 * n + 1; i++) {
            if (!vst[i]) {
                vst[i] = true;
                cout << i << endl;
                break;
            }
        }
    }
    cout << flush;
}

int main() {
    solve();
    return 0;
}

