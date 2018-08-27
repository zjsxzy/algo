/*
ID: frankzh1
TASK: ride
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int str2int(string s) {
    int mul = 1;
    for (int i = 0; i < s.size(); i++) {
        mul *= (s[i] - 'A' + 1);
    }
    return mul % 47;
}

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    if (str2int(s) == str2int(t)) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    return 0;
}
