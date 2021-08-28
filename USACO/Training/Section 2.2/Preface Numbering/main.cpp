/*
ID: frankzh1
TASK: preface
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

map<char, int> cnt;

void roman(int x) {
    int tot = 0;
    while (x) {
        tot++;
        char c1, c2, c3;
        if (tot == 1) {
            c1 = 'I', c2 = 'V', c3 = 'X';
        } else if (tot == 2) {
            c1 = 'X', c2 = 'L', c3 = 'C';
        } else if (tot == 3) {
            c1 = 'C', c2 = 'D', c3 = 'M';
        } else {
            c1 = 'M';
        }
        int p = x % 10;
        if (p <= 3) {
            cnt[c1] += p;
        } else if (p == 4) {
            cnt[c1]++; cnt[c2]++;
        } else if (p >= 5 && p <= 8) {
            cnt[c1] += p - 5; cnt[c2]++;
        } else if (p == 9) {
            cnt[c1]++; cnt[c3]++;
        }
        x /= 10;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        roman(i);
    }
    if (cnt['I']) cout << "I " << cnt['I'] << endl;
    if (cnt['V']) cout << "V " << cnt['V'] << endl;
    if (cnt['X']) cout << "X " << cnt['X'] << endl;
    if (cnt['L']) cout << "L " << cnt['L'] << endl;
    if (cnt['C']) cout << "C " << cnt['C'] << endl;
    if (cnt['D']) cout << "D " << cnt['D'] << endl;
    if (cnt['M']) cout << "M " << cnt['M'] << endl;
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    solve();
    return 0;
}

