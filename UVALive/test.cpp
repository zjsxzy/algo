#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;

//三维点
struct pt3
{
	ll x, y, z;
	pt3(){}
	pt3(ll _x, ll _y, ll _z): x(_x), y(_y), z(_z){}
	void read()
	{
		cin >> x >> y >> z;
	}
	pt3 operator - (const pt3 p1){return pt3(x - p1.x, y - p1.y, z - p1.z);}
	pt3 operator + (const pt3 p1){return pt3(x + p1.x, y + p1.y, z + p1.z);}
	pt3 operator * (pt3 p){return pt3(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);}		//叉乘 
	ll operator ^ (pt3 p){return x*p.x+y*p.y+z*p.z;}							//点乘 
};

ll vlen2(const pt3 &a){return a.x*a.x+a.y*a.y+a.z*a.z;}
ll dis2(const pt3 &a, const pt3 &b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);}

pair<ll, ll> ptoseg2(pt3 p, pt3 l1, pt3 l2){
	if (((p - l2) ^ (l1 - l2)) <= 0)return make_pair(dis2(p, l2), 1);
	if (((p - l1) ^ (l2 - l1)) <= 0)return make_pair(dis2(p, l1), 1);
	return make_pair(vlen2((p-l1)*(l2-l1)), dis2(l1, l2));
}

///////////////////////////////////////////////////

pt3 A, B, C, D, v;
ll ans1, ans2;

bool ok()
{
	ll v1 = ((C - D) * v) ^ (A - C);
	ll v2 = ((C - D) * v) ^ (B - C);
	if (v1 >= 0 && v2 >= 0)return false;
	if (v1 <= 0 && v2 <= 0)return false;
	
	ll v3 = ((A - B) * v) ^ (C - A);
	ll v4 = ((A - B) * v) ^ (D - A);
	if (v3 >= 0 && v4 >= 0)return false;
	if (v3 <= 0 && v4 <= 0)return false;
	return true;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		A.read();
		B.read();
		C.read();
		D.read();
		v = (A - B) * (C - D);
		
		if (ok())
		{
			ans1 = (C - A) ^ v;
			ans1 *= ans1;
			ans2 = vlen2(v);
		} else
		{
			pair<ll, ll>ans = make_pair(10000000LL, 1LL), tmp;
			tmp = ptoseg2(A, C, D);
			if (tmp.first * ans.second < ans.first * tmp.second) ans = tmp;
			tmp = ptoseg2(B, C, D);
			if (tmp.first * ans.second < ans.first * tmp.second) ans = tmp;
			tmp = ptoseg2(C, A, B);
			if (tmp.first * ans.second < ans.first * tmp.second) ans = tmp;
			tmp = ptoseg2(D, A, B);
			if (tmp.first * ans.second < ans.first * tmp.second) ans = tmp;
			ans1 = ans.first;
			ans2 = ans.second;
		}
		if (ans1 < 0 || ans2 < 0)while (1);
		ll gcd = __gcd(ans1, ans2);
		ans1 /= gcd;
		ans2 /= gcd;

		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
