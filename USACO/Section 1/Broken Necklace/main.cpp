/*
ID: frankzh1
TASK: beads 
LANG: C++
*/
#include <string>
#include <iostream>
using namespace std;

int n;
string s;

int next(int p) {
    if (p == n - 1) return 0;
    else return p + 1;
}

int prev(int p) {
    if (p == 0) return n - 1;
    else return p - 1;
}

int search(int start) {
    int cur = start, sum = 1;
    char color = s[cur];
    while (true) {
        cur = next(cur);
        if (cur == start) break;
        if (color == 'w') {
            sum++;
            if (s[cur] != 'w') {
                color = s[cur];
            }
        } else {
            if (s[cur] == 'w' || s[cur] == color) {
                sum++;
            } else {
                break;
            }
        }
    }

    if (start == cur) return sum; 

    int pos = prev(cur);
    cur = prev(start);
    // cout << cur << " " << pos << endl;
    sum++;
    color = s[cur];
    while (true) {
        cur = prev(cur);
        if (cur == pos || cur == start) break;
        if (color == 'w') {
            sum++;
            if (s[cur] != 'w') {
                color = s[cur];
            }
        } else {
            if (s[cur] == 'w' || s[cur] == color) {
                sum++;
            } else {
                break;
            }
        }
    }

    return sum;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin >> n >> s;
    int res = 0;
    search(2);
    for (int i = 0; i < n; i++) {
        int sum = search(i);
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}