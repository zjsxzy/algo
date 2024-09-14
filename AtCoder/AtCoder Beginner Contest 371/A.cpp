#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    vector<char> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    if (v[0] == '>' && v[1] == '<') cout << 'A' << endl;
    else if (v[0] == '<' && v[1] == '>') cout << 'A' << endl;
    else if (v[0] == '<' && v[2] == '<') cout << 'B' << endl;
    else if (v[0] == '>' && v[2] == '>') cout << 'B' << endl;
    else cout << 'C' << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}