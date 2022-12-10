#include <iostream>
#include <complex>
#include <iomanip>
#include <vector>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
const ld E = 1e-8;
inline ld cp(const pt& a, const pt& b) {
	return a.real()*b.imag()-a.imag()*b.real();
}
inline int scp(const pt& a, const pt& b) {
	ld s = cp(a,b);
	return abs(s)<E?0:(s<0?-1:1);
}
inline pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d){
	  return a + cp(c - a, d - c)/cp(b - a, d - c) * (b - a); } 

void output(vector<pt> I) {
	bool good = true;
	for (int i=0; i < I.size(); i++) for (int j=i+1; j < I.size(); j++) {
		if (abs(I[i]-I[j]) > E) good = false;
	}
	cout << (good ? "YES" : "NO") << endl;
	if (good) {
		cout << fixed << setprecision(1) << I[0].real() << " " << I[0].imag() << endl;
	}
}

int main() {
	ld X, Y, S, px, py; cin >> X >> Y >> S >> px >> py;
	pt P(px,py),A(X-S/2,Y-S/2),B(X-S/2,Y+S/2),C(X+S/2,Y+S/2),D(X+S/2,Y-S/2);
	//cerr << P << " " << A << " " << B << " " << C << " " << D << endl;
	pt AP=P-A, BP=P-B, CP=P-C, DP=P-D;
	pt Ap = BP*pt(0,1), Bp=CP*pt(0,1), Cp=DP*pt(0,1), Dp=AP*pt(0,1);
	
	if (scp(AP,BP)==0||scp(BP,CP)==0||scp(CP,DP)==0||scp(DP,AP)==0
			||scp(AP,CP)==0||scp(BP,DP)==0) {
		vector<pt> I;
		if(scp(BP,CP)) I.push_back(line_inter(A,A+Ap,B,B+Bp));
		if(scp(BP,DP)) I.push_back(line_inter(A,A+Ap,C,C+Cp));
		if(scp(BP,AP)) I.push_back(line_inter(A,A+Ap,D,D+Dp));
		if(scp(CP,DP)) I.push_back(line_inter(B,B+Bp,C,C+Cp));
		if(scp(CP,AP)) I.push_back(line_inter(B,B+Bp,D,D+Dp));
		if(scp(DP,AP)) I.push_back(line_inter(C,C+Cp,D,D+Dp));
		output(I);
		return 0;	
	}

	if (scp(Ap,Bp)==0||scp(Ap,Cp)==0||scp(Ap,Dp)==0
			||scp(Bp,Cp)==0||scp(Bp,Dp)==0||scp(Cp,Dp)==0) {
		cout << "NO" << endl;
		return 0;
	}

	vector<pt> I(6);
	I[0]=line_inter(A,A+Ap,B,B+Bp),
	I[1]=line_inter(A,A+Ap,C,C+Cp),
	I[2]=line_inter(A,A+Ap,D,D+Dp),
	I[3]=line_inter(B,B+Bp,C,C+Cp),
	I[4]=line_inter(B,B+Bp,D,D+Dp),
	I[5]=line_inter(C,C+Cp,D,D+Dp);
	output(I);
	return 0;
}