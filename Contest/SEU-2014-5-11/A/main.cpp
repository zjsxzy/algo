#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

void solve(int n, vector<int> state) {
	int ret = 100000000;
	int a = 0, b = 0, c = 0;
	for (int s = 0; s < (1 << n); s++) {
		int a = state[s];
		int rest = s ^ ((1 << n) - 1);
		for (int k = rest; k > 0; ) {
			b = state[k];
			c = state[rest ^ k];
			if (b >= a && c >= a) {
				if (max(b, c) - a < ret) {
					ret = max(b, c) - a;
				}
			}
			k = (k - 1) & rest;
		}
	}
	cout << ret << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		int n;
		cin >> n;
		vector<int> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		vector<int> state(1 << n);
		int ret = 10000000;
		for (int s = 0; s < (1 << n); s++) {
			for (int i = 0; i < n; i++) {
				if (s & (1 << i)) state[s] += x[i];
			}
		}
		solve(n, state);
	}
	return 0;
}

