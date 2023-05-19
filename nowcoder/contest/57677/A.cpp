#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int pow_mod(int a, int i, int n) {
	if (i == 0) return 1 % n;
	int res = 1;
	for (; i; i >>= 1) {
		if (i & 1) res = (long long)res * a % n;
		a = (long long)a * a % n;
	}
	return res;
}

bool test(int n, int a, int d) {
	if (n == 2) return true;
	if (n == a) return true;
	if ((n & 1) == 0) return false;
	while (!(d & 1)) d = d >> 1;
	int t = pow_mod(a, d, n);
	while ((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = (long long)t * t % n;
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}

bool isPrime(int n) {
	if (n < 2) return false;
	int a[] = {2, 3, 61}; //测试集，更广的测试范围需要更大的测试集
	for (int i = 0; i < 3; i++) {
		if (!test(n, a[i], n - 1)) return false;
 	}
 	return true;
}

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        cout << 4 << endl;
        return;
    }
    if (n % 2 == 0) n--;
    while (!isPrime(n)) {
        n -= 2;
    }
    cout << n << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}