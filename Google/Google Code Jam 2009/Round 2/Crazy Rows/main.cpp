#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> mat(n);
    for (auto& s: mat) cin >> s;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '1') a[i] = j;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = i; j < n; j++) {
            if (a[j] <= i) {
                pos = j;
                break;
            }
        }
        for (int j = pos; j > i; j--) {
            swap(a[j], a[j - 1]);
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

