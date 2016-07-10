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

#define MAX_ITERATION 100000

double precision = 1e-10;

double DCF(vector<double> cf, double dis) {
	double dcf = 0;
	double ncf = 0;
	for(int i = 0; i < cf.size(); i++) {
        if (i == 0) dcf -= cf[i];
        else {
		    ncf = cf[i] / pow((1 + dis), i);
		    dcf += ncf;
        }
	}
	return dcf;
}

double IRR(vector<double>& cf) {
	double npv = 0;
	double res = 0;
	double low = -1;
	double high = 1;
	bool flag = false;

	if (DCF(cf, low) < DCF(cf, high)) {
		flag = true;
	}

	for (int i = 0; i < MAX_ITERATION; i++) {
		res = (low + high) / 2;
		npv = DCF(cf, res);
		if(fabs(npv) < precision)
            break;

		if ((npv > 0 && !flag) || (npv < 0 && flag)) {
			low = res;
			if (low == high)
                high *= 2;
		} else {
			high = res;
			if (low == high)
                low *= 2;
		}
	}
	return res;
}

int main() {
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        int n;
        cin >> n;
        vector<double> cf;
        for (int i = 0; i < n + 1; i++) {
            double x;
            cin >> x;
            cf.PB(x);
        }
        double res = IRR(cf);
        printf("Case #%d: %.12f\n", cas, res);
    }
    return 0;
}
