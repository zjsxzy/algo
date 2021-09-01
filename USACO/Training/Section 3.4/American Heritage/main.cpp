/*
ID: frankzh1
TASK: heritage
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void search(string pre, string inor) {
    int n = pre.size();
    if (n == 0) return;
    char root = pre[0];
    int k = inor.find(root);
    pre.erase(pre.begin());
    string leftpre = pre.substr(0, k);
    string rightpre = pre.substr(k);
    string leftinor = inor.substr(0, k);
    string rightinor = inor.substr(k + 1);
    search(leftpre, leftinor);
    search(rightpre, rightinor);
    cout << root;
}

void solve() {
    string pre, inor;
    cin >> inor >> pre;
    search(pre, inor);
    cout << endl;
}

int main() {
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    solve();
    return 0;
}

