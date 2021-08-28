/*
ID: frankzh1
TASK: fracdec
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void output(string& s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && i % 76 == 0) cout << endl;
        cout << s[i];
    }
    cout << endl;
}

void solve() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    string fraction = to_string(numerator / denominator);
    int remainder = numerator % denominator;
    if (remainder == 0) {
        fraction.append(".0");
        output(fraction);
        return;
    }
    fraction.append(".");
    map<int, int> mp;
    while (remainder != 0) {
        if (mp.find(remainder) != mp.end()) {
            fraction.insert(mp[remainder], "(");
            fraction.append(")");
            break;
        }
        mp[remainder] = fraction.size();
        remainder *= 10;
        fraction.append(to_string(remainder / denominator));
        remainder %= denominator;
    }
    output(fraction);
}

int main() {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    solve();
    return 0;
}

