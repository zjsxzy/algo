#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e7;
void solve() {
    string s;
    cin >> s;
    int n = s.size(), res = inf;
    vector<vector<int>> mat(26, vector<int>(26, inf));
    for (int i = 0; i < 26; i++) mat[i][i] = 0;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        string chg;
        cin >> chg;
        mat[chg[0] - 'A'][chg[1] - 'A'] = 1;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        string t(n, 'A' + c);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[s[i] - 'A'][t[i] - 'A'];
        }
        if (sum < res) res = sum;
    }
    if (res == inf) res = -1;
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
    return 0;
}

