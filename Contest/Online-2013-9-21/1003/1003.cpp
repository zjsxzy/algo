#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
struct edge{
	int a, b, w, sum;
	bool operator<(const edge& e)const{
		return w < e.w;
	}
}e[500100];
int f[11000],s[11000], n, m;
int find(int p){
	return f[p] == p? p : f[p] = find(f[p]);
}
void uni(int a, int b){
	int j = find(a);
	int k = find(b);
	if (j != k){
		s[k] += s[j];
		f[j] = k;
	}
}
void fsinit(){
	for (int i = 0; i < n; i ++){
		f[i] = i;
		s[i] = 1;
	}
}
int divf(int p){
	int min = 0, max = m;
	while (max != min){
		int mid = (max + min) >>1;
		if (e[mid].w < p) 
			min = mid + 1;
		else
			max = mid;
	}
	return e[max].sum * 2;
}
bool doone(){
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	fsinit();
	for (int i = 0; i < m; i ++){
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
	}
	e[m].w = 0x3f3f3f3f;
	sort(e, e + m);
	for (int i = 0; i < m; i ++){
		int j = find(e[i].a);
		int k = find(e[i].b);
		if (j != k){
			e[i].sum = s[j] * s[k];
			s[k] += s[j];
			f[j] = k;
		}else{
			e[i].sum = 0;
		}
	}
	for (int i = m - 1; i > -1; i --)
		e[i].sum += e[i + 1].sum;
	int p;
	scanf("%d", &p);
	while (p --){
		int c;
		scanf("%d", &c);
		printf("%d\n", divf(c));
	}	
	return true;
}
int main(){
	while (doone());
	return 0;
}
