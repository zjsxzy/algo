#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 20;
const int M = 1e9 + 7;
int n, m;
string color[N];
int dp[2][1 << 20];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
		cin >> color[i];
	}
    int *crt = dp[0]; int *next = dp[1];
	crt[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			for (int used = 0; used < 1 << m; used++) {
				if ((used >> j & 1) || color[i][j] == '*') {
					//不需要放置
					next[used] = crt[used & ~(1 << j)];
				}
				else {
					//尝试两种放置
					int res = 0;
					//横着放
					if (j + 1 < m && !(used >> (j + 1) & 1) && color[i][j + 1] != '*') {
						res += crt[used | 1 << (j + 1)];
					}

					//竖着放
					if (i + 1 < n && color[i + 1][j] != '*') {
						res += crt[used | 1 << j];
					}
					next[used] = res % M;
				}
			}
			swap(crt, next);
		}
	}
	cout << crt[0] << endl;
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