#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxm = 555;
const int maxn = 1205;
const char *ch = "abcdefghijklmnopqrstuvwxyz";
int nf, n;
vector<string> sf, s;
int diff[maxm][maxn], Min[maxn][3], f[maxn];
char r[maxn][3];
string ans[maxn];

void solve() {
    cin >> n;
    s.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    cout << s[4] << endl;
    for (int i = 1; i <= nf; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            for (int k = 0; k < 20; k++) {
                sum += (sf[i][k] != s[j][k]);
            }
            diff[i][j] = sum;
        }
    }

    memset(Min, 32, sizeof(Min));
    for (int i = 1; i <= nf; i += 20) { // 枚举字母
        for (int j = 1; j <= n; j++) { // 枚举行
            if (j + 19 <= n) { // 01替换
                int tot = 0;
                for (int k = 0; k < 20; k++) {
                    tot += diff[i + k][j + k];
                }
                if (tot < Min[j][1]) {
                    Min[j][1] = tot;
                    r[j][1] = tot > 120 ? '?' : ch[i / 20];
                }
            }
            for (int k = 0; k < 21; k++) {
                if (k < 20 && j + 18 <= n) { // 丢失一行
                    int tot = 0;
                    for (int p = 0; p < k; p++) tot += diff[i + p][j + p];
                    for (int p = k; p < 19; p++) tot += diff[i + p + 1][j + p];
                    if (tot < Min[j][0]) {
                        Min[j][0] = tot;
                        r[j][0] = tot > 120 ? '?' : ch[i / 20];
                    }
                }
                if (j + 20 <= n) { // 复制一行
                    int tot = 0;
                    for (int p = 0; p < k; p++) tot += diff[i + p][j + p];
                    for (int p = k; p < 21; p++) tot += diff[i + p][j + p + 1];
                    if (tot < Min[j][2]) {
                        Min[j][2] = tot;
                        r[j][2] = tot > 120 ? '?' : ch[i / 20];
                    }
                }
            }
        }
    }
    fill(f + 1, f + 19, 0x3f3f);
    for (int i = 19; i <= n; i++) {
        f[i] = f[i - 19] + Min[i - 18][0];
        ans[i] = ans[i - 19] + r[i - 18][0];
        if (i >= 20 && f[i - 20] + Min[i - 19][1] < f[i]) {
            f[i] = f[i - 20] + Min[i - 19][1];
            ans[i] = ans[i - 20] + r[i - 19][1];
        }
        if (i >= 21 && f[i - 21] + Min[i - 20][2] < f[i]) {
            f[i] = f[i - 21] + Min[i - 20][2];
            ans[i] = ans[i - 20] + r[i - 20][2];
        }
    }
    cout << ans[n] << endl;
}

int main() {
    freopen("font.in", "r", stdin);
    cin >> nf;
    sf.resize(nf + 1);
    for (int i = 1; i <= nf; i++) {
        cin >> sf[i];
    }
    freopen("charrec.in", "r", stdin);
    //freopen("charrec.out", "w", stdout);
    solve();
    return 0;
}

