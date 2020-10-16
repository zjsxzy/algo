#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

long long n;
int p[11111], prime[11111], m = 0;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	long long nn = n;
	int ret, step;
	for (int i = 2; i <= (int)sqrt(n) && nn > 1; i++)
	    if (nn % i == 0) {
		    m++;
			prime[m] = i;
			while (nn % i == 0) {
				p[m]++;
				nn /= i;
			}
		}
	if (m == 1 && nn > 1) {
		m++;
		prime[m] = nn;
		p[m] = 1;
	}
	if (m >= 2) {
		if (m == 2 && p[1] == 1 && p[2] == 1) {
			ret = 2;
		}else {
			ret = 1;
			step = prime[1] * prime[2];
		}
	}
	else if (m == 1) {
		if (p[m] == 1) {
			ret = 1;
			step = 0;
		}else if (p[m] == 2) {
			ret = 2;
			
		} else {
			ret = 1;
			step = prime[m] * prime[m];
		}
	}else {
		ret = 1;
		step = 0;
	}
	cout << ret << endl;
	if (ret == 1)
		cout << step << endl;
	return 0;
}
