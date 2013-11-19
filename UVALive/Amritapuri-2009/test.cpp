#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 6;
typedef double db;
const db EPS = 1e-8;
int sign(db x){return x < - EPS ? - 1 : x > EPS;}
db sqr(db x){return x * x;}

db min(db x,db y){if(sign(x - y) < 0) return x ; return y;}
bool bet(db x,db a,db b){
	return sign(x - a) >= 0 && sign(x - b) <= 0;
}
struct TPoint{
	db x,y;
	TPoint(){}
	TPoint(db xx,db yy):x(xx),y(yy){}
	TPoint operator-(const TPoint P){return TPoint(x - P.x, y - P.y);}
	TPoint operator+(const TPoint P){return TPoint(x + P.x, y + P.y);}
	TPoint operator*(const db P){return TPoint(x * P, y * P);}
	TPoint operator/(const db P){return TPoint(x / P, y / P);}
	db X(TPoint P) {return x * P.y - y * P.x;}
	db O(TPoint P) {return x * P.x + y * P.y;}
	db len(){return sqrt(sqr(x) + sqr(y));}
	void get(){scanf("%lf%lf",&x,&y);}
	void out(){printf("(%.3f,%.3f)\n",x,y);}
}A[30], B[30] , vA, vB,nowV;

db cross(TPoint a,TPoint b,TPoint c){return (b - a).X(c - a);}
struct TLine{
	TPoint a,b;
	db B,A,C;
	void init(TPoint aa,TPoint bb){
		a = aa;
		b = bb;
		A = a.x - b.x;
		B = b.y - a.y;
		C = b.X(a);
	}
	bool inter(TLine L, TPoint &P){
		TPoint AA(A,L.A), BB(B,L.B), CC(C, L.C);
		db c = AA.X(BB);
		if(! sign(c)) return 0;
		P = TPoint(CC.X(AA) / c, - CC.X(BB) / c);
		return 1;
		return 1;
	}
	bool on_seg(TPoint P){
		db x0 = min(a.x, b.x), x1 = max(a.x, b.x), y0 = min(a.y, b.y), y1 = max(a.y, b.y);
		return bet(P.x, x0, x1) && bet(P.y, y0, y1);
	}
	bool on_xay(TPoint P){ // a--->b
		//if(sign( (P - a).X(b - a) )) return 0; //no on_line...
		return sign((P - a).O(b - a)) >= 0;
	}
}nowL,tmpL;

void get(){
	int i;
	for(i = 0; i < 3; ++ i) A[i].get(); vA.get(); A[3] = A[0];
	for(i = 0; i < 3; ++ i) B[i].get(); vB.get(); B[3] = B[0];
}

void work(){
	int i,j;
	TPoint jiao ;
	db ans = 1e100;
	//case 1...
	nowV = vA - vB; // vB = 0 ...
	if(sign( nowV.len()) == 0) {
		puts("NO COLLISION");
		return ;
	}
	for(i = 0; i < 3; ++ i){
		nowL.init(A[i] , A[i] + nowV);
		for(j = 0; j < 3; ++ j){
			tmpL.init( B[j], B[j + 1]);
			bool flg = tmpL.inter(nowL, jiao);
			if(flg){
				if(tmpL.on_seg(jiao) && nowL.on_xay(jiao)) {
					cout << i << " " << j << " " << j + 1 << endl;
					jiao.out();
					db cc = (jiao - A[i]).len() / nowV.len();
					if(sign(ans - cc) > 0) ans = cc;
				}

			}
		}
	}



	//case 2...
		nowV = vB - vA; // vA = 0 ...
		for(i = 0; i < 3; ++ i){
			nowL.init(B[i] , B[i] + nowV);
			for(j = 0; j < 3; ++ j){
				tmpL.init( A[j], A[j + 1]);
				bool flg = tmpL.inter(nowL, jiao);
				if(flg){
					if(tmpL.on_seg(jiao) && nowL.on_xay(jiao)) {
						db cc = (jiao - B[i]).len() / nowV.len();
						if(sign(ans - cc) > 0) ans = cc;
					}

				}
			}
		}
	if(ans < 1e90) printf("%.9lf\n",ans);
	else puts("NO COLLISION");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T --){
		get();
		work();
	}
	return 0;
}
