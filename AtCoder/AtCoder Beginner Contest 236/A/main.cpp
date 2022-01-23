#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    a--; b--;
    char c = s[a]; s[a] = s[b]; s[b] = c;
    cout << s << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

