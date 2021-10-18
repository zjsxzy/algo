#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int a = 0, b = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		if (x == 1) a++;
		else if (x == 2) b++;
	}
	if (a > b) cout << "INDIA" << endl;
	else if (a < b) cout << "ENGLAND" << endl;
	else cout << "DRAW" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		solve(); 
	}
    return 0;
}

