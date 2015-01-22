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
double compute(double a, double b, double c, double d, double x) {
    return a*x*x*x + b*x*x + c*x + d;
}

double getResult(double a, double b, double c, double d,double x1,double x2){
	double result=(x1+x2)/2;
	while(abs(compute(a,b,c,d,result))>=0.001){
		if(compute(a,b,c,d,result)*compute(a,b,c,d,x1) < 0){
			x2=result;
			result=(x1+result)/2;
		}
		if(compute(a,b,c,d,result)*compute(a,b,c,d,x2) < 0){
			x1=result;
			result=(x2+result)/2;
		}
		//cout<<result<<endl;
	}
	return result;
}

int main(){
	double a,b,c,d;
	double x_1,x_2,x1,x2,x3;
	cin>>a>>b>>c>>d;

	x_1=(-b+sqrt(pow(b,2)-3*a*c))/(3*a);
	x_2=(-b-sqrt(pow(b,2)-3*a*c))/(3*a);
	if(x_1>x_2){
		x_1=x_2;
		x_2=(-b+sqrt(pow(b,2)-3*a*c))/(3*a);
	}
	x1=getResult(a,b,c,d,-100,x_1);
	x2=getResult(a,b,c,d,x_1,x_2);
	x3=getResult(a,b,c,d,x_2,100);

    printf("%.2f %.2f %.2f\n", x1, x2, x3);
	//cout<<setiosflags(ios::fixed)<<setprecision(2)<<x1<<" "<<x2<<" "<<x3<<endl;
	return 0;
};
