#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// ax+by=1
int extend_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	} else {
		int r = extend_gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

// ax+by=c
void linear_equation(int a, int b, int c, int& x, int& y) {
    int d = extend_gcd(a, b, x, y);
    if (c % d != 0) return;
    int k = c / d;
    x *= k;
    y *= k;
}

void linear_equation_all(int a, int b, int c, int& x, int& y) {
    linear_equation(a, b, c, x, y);
    int d = gcd(a, b);
    for (int i = -5; i <= 5; i++) {
        int x_all = x - b / d * i;
        int y_all = y + a / d * i;
        cout << x_all << ' ' << y_all << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x: A) cin >> x;
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    for (int i = 0; i < n; i++) {
        if (A[i] % g != 0) {
            cout << -1 << endl;
            return;
        }
        int x, y;
        linear_equation(a, b, A[i], x, y);
        cout << A[i] << ' ' << x << ' ' << y << endl;
    }
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

