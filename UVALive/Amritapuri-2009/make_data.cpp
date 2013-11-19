#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	freopen("input", "w", stdout);
	int n = 10;
	cout << n << endl;
	for (; n--; ) {
		for (int i = 0; i < 8; i++) {
			cout << rand() % 10000000 << " ";
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			cout << rand() % 10000000 << " ";
		}
		cout << endl;
	}
	return 0;
}
