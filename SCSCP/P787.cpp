#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int Manchester(string& s) {
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
    return res - 1;
}

void solve() {
    string s;
    cin >> s;
    cout << Manchester(s) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}