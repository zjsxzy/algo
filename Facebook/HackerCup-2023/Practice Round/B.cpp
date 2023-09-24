#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int cs) {
    cout << "Case #" << cs << ": ";
    int r, c, a, b;
    cin >> r >> c >> a >> b;
    int A = r / a + r % a != 0, B = c / b + c % b != 0;
    if (r > c && A <= B) cout << "YES" << endl;
    else cout << "NO" << endl; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve(t);
    }
    return 0;
}