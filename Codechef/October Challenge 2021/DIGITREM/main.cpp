#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string s;
    int d;
    cin >> s >> d;
    LL n = stoi(s);
    if (d == 0) {
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (flag) s[i] = '1';
            else if (s[i] == '0') {
                s[i] = '1';
                flag = true;
            }
        }
        LL res = stoi(s);
        cout << res - n << endl;
        return;
    }
    if (d == 9) {
        string temp;
        temp.PB('0');
        for (int i = 0; i < s.size(); i++) {
            temp.PB(s[i]);
        }
        bool flag = false;
        for (int i = 0; i < temp.size(); i++) {
            if (flag) temp[i] = '0';
            else if (temp[i] == d + '0') {
                int num = temp[i - 1];
                num++;
                temp[i - 1] = char(num);
                temp[i] = '0';
                flag = true;
                if (temp[i - 1] == '9') {
                    i -= 2;
                    flag = false;
                }
            }
        }
        LL res = stoi(temp);
        cout << res - n << endl;
        return;
    }
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (flag) s[i] = '0';
        else if (s[i] == d + '0') {
            s[i] = d + '1';
            flag = true;
        }
    }
    LL res = stoi(s);
    cout << res - n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

