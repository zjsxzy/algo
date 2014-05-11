#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const double eps = 1e-6;
struct Point {
	double x, y, z;
	double t;
	void input() {
		scanf("%lf%lf%lf", &x, &y, &z);
		t = x * x + y * y + z * z;
	}
	void output() {
		printf("%.0f %.0f %.0f\n", x, y, z);
	}
}p1, p2, p3, p4;
double d1, d2, d3, d4;
double equ[4][4], X[4];

int Gauss(int n, int m) {
	int Rank = 0;
	for (int j = 0, i; j < m && Rank < n; j++) {	
		for (i = Rank; i < n && abs(equ[i][j]) < eps; i++);
		if (i >= n)		
			continue;
		if (i != Rank) {
				for (int k = j; k <= m; k++)
					swap(equ[Rank][k], equ[i][k]);
			}
		for (int k = m; k >= j; k--)
			equ[Rank][k] /= equ[Rank][j];
			
		for (i = Rank + 1; i < n; i++) if (abs(equ[i][j]) > eps) {
			for (int k = m; k >= j; k--)
				equ[i][k] = equ[i][k] - equ[Rank][k] * equ[i][j];
		}
		Rank++;
	}
	for (int i = Rank - 1, pre = m, key; i >= 0; i--) {
		for (key = 0; abs(equ[i][key]) < eps; key++);
		for (int k = key + 1; k < pre; k++)
			X[k] = 0.0;		//自由元
		double sum = equ[i][m];
		for (int k = key + 1; k < m; k++)
			sum -= X[k] * equ[i][k];
		X[pre = key] = sum;
	}
	return 1;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		memset(X, 0, sizeof(X));
		memset(equ, 0, sizeof(equ));
		p1.input();
		p2.input();
		p3.input();
		p4.input();
		scanf("%lf%lf%lf%lf", &d1, &d2, &d3, &d4);
		if (abs(d1) < eps) {
			p1.output();
			continue;
		}
		if (abs(d2) < eps) {
			p2.output();
			continue;
		}
		if (abs(d3) < eps) {
			p3.output();
			continue;
		}
		if (abs(d4) < eps) {
			p4.output();
			continue;
		}
		equ[0][0] = 2.0 * (p1.x - p2.x); equ[1][0] = 2.0 * (p1.x - p3.x); equ[2][0] = 2.0 * (p1.x - p4.x);
		equ[0][1] = 2.0 * (p1.y - p2.y); equ[1][1] = 2.0 * (p1.y - p3.y); equ[2][1] = 2.0 * (p1.y - p4.y);
		equ[0][2] = 2.0 * (p1.z - p2.z); equ[1][2] = 2.0 * (p1.z - p3.z); equ[2][2] = 2.0 * (p1.z - p4.z);
		equ[0][3] = (d2 - p2.t) - (d1 - p1.t); 
		equ[1][3] = (d3 - p3.t) - (d1 - p1.t);
		equ[2][3] = (d4 - p4.t) - (d1 - p1.t);
		Gauss(3, 3);
		if (abs(X[0]) < eps) X[0] = 0;
		if (abs(X[1]) < eps) X[1] = 0;
		if (abs(X[2]) < eps) X[2] = 0;
		printf("%.0f %.0f %.0f\n", X[0], X[1], X[2]);
	}
	return 0;
}

