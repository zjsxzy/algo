/*
ID: frankzh1
TASK: zerosum
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n;
vector<char> opr;
vector<string> res;

void dfs(int i, int sum) {
    if (i == n) {
        if (sum == 0) {
            string s = "";
            for (int i = 1; i < n; i++) {
                s += '0' + i;
                s += opr[i - 1];
            }
            s += '0' + n;
            res.push_back(s);
        }
        return;
    }
    opr.push_back('+');
    dfs(i + 1, sum + i + 1);
    opr.pop_back();

    opr.push_back('-');
    dfs(i + 1, sum - (i + 1));
    opr.pop_back();

    int sz = opr.size();
    int t = 10 * i + i + 1;
    if (sz > 0 && opr[sz - 1] == '-') {
        opr.push_back(' ');
        dfs(i + 1, sum + i - t);
        opr.pop_back();
    } else if (sz == 0 || opr[sz - 1] == '+') {
        opr.push_back(' ');
        dfs(i + 1, sum - i + t);
        opr.pop_back();
    }
}

void solve() {
    cin >> n;
    dfs(1, 1);
    sort(res.begin(), res.end());
    for (auto &s: res) {
        cout << s << endl;
    }
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    solve();
    return 0;
}

