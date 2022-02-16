#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

string vowel = "AEIOUaeiou";

void solve(int cs) {
	printf("Case #%d: ", cs);
	string name;
	cin >> name;
	char c = name[name.size() - 1];
	if (c == 'y' || c == 'Y') {
		cout << name << " is ruled by nobody." << endl;
		return;
	}
	for (auto v: vowel) {
		if (v == c) {
			cout << name << " is ruled by Alice." << endl;
			return;
		}
	}
	cout << name << " is ruled by Bob." << endl;
}

int main() {
	int ts;
	cin >> ts;
	for (int cs = 1; cs <= ts; cs++) {
		solve(cs);
	}
    return 0;
}

