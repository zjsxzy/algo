#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void add(int& h, int& m, int x) {
    h += x / 60;
    m += x % 60;
    if (m >= 60) {
        h++;
        m -= 60;
    }
    if (h >= 24) {
        h -= 24;
    }
}

void solve() {
    string ti;
    int x;
    cin >> ti >> x;
    int h = stoi(ti.substr(0, 2)), m = stoi(ti.substr(3, 2));
    int res = 0;
    auto palindrome = [&](int i, int j) {
        if (i / 10 == j % 10 && i % 10 == j / 10) return true;
        return false;
    };
    int i = h, j = m;
    if (palindrome(i, j)) res++;
    add(i, j, x);
    while (i != h || j != m) {
        if (palindrome(i, j)) res++;
        add(i, j, x);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

