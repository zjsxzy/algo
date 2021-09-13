/*
ID: frankzh1
TASK: calfflac
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

pair<int, int> Manchester(string& s) {
	int n = s.size();
    string str(n * 2 + 1, ' ');
	int j = 0;
	for (int i = 0; i < n; i++) {
		str[j++] = '#';
		str[j++] = s[i];
	}
	str[j++] = '#';
	n = j;

    int res = 0;
	int right = -1, id = -1;
    vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		int r = 1;
		if (right >= i) {
			r = max(r, min(right - i + 1, dp[2 * id - i]));
		}
		while ((i - r + 1 >= 0 && i + r - 1 < n) && str[i - r + 1] == str[i + r - 1])
			r++;
		r--;
		if (i + r - 1 > right) {
			right = i + r - 1;
			id = i;
		}
		dp[i] = r;
        if (r > res) res = r;
	}
    int maxLen = res - 1, center = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > dp[center]) center = i;
    }
    int start = (center - maxLen) / 2;
    // cout << s.substr(start, maxLen) << endl;
    return {start, maxLen};
}

const int maxn = 20005;
char ori_s[maxn];
int idx[maxn];

void solve() {
    char c;
    string s;
    int i = 0, j = 0;
    while (scanf("%c", &ori_s[i]) != EOF) {
        char c = ori_s[i];
        if (isalpha(c)) {
            s += tolower(c);
            idx[j] = i;
            j++;
        }
        i++;
    }
    pair<int, int> res = Manchester(s);
    cout << res.second << endl;
    // cout << s.substr(res.first, res.second) << endl;
    int l = idx[res.first], r = idx[res.first + res.second - 1];
    for (int i = l; i <= r; i++) {
        printf("%c", ori_s[i]);
    }
    cout << endl;
}

int main() {
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    solve();
    return 0;
}

