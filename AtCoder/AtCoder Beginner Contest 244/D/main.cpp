#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

char t1, t2, t3;
bool flag;

void dfs(char s1, char s2, char s3, int step) {
    if (step > 2) return;
    if (flag) return;
    if (s1 == t1 && s2 == t2 && s3 == t3) {
        if (step == 2) {
            flag = true;
            return;
        }
    }
    dfs(s2, s1, s3, step + 1);
    dfs(s1, s3, s2, step + 1);
    dfs(s3, s2, s3, step + 1);
}

void solve() {
    char s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cin >> t1 >> t2 >> t3;
    flag = false;
    dfs(s1, s2, s3, 0);
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

