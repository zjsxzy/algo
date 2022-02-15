#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve(int cs) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    printf("Case #%d: %d\n", cs, sum % m);
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        solve(cs);
    }
    return 0;
}

