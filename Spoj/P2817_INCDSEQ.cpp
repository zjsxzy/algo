/*
 * 一个N个元素的序列S1, ..., SN, 求长度为K的不同的递增序列的个数
 * f(i,j)表示长度为i，以第j个元素结尾的方案数，则f(i,j)=sigma(f(i-1,k)|(pre[j]<k<j且Sk<Sj))，pre[j]表示在j之前最近的那个与第j个元素值相等的位置，统计的时候可以先离散化然后用树状数组统计，但是要去掉重复的那些，也就是f[i][j] = f[i][j] - f[i][pre[j]]。
 */
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

const int maxn = 10005;
const int mod = 5000000;
struct BinaryIndexTree {
	int N;
	int C[maxn];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i)) {
			C[i] += num;
			C[i] %= mod;
		}
	}
	
	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i)) {
			ret += C[i];
			ret %= mod;
		}
		return ret;
	}
}tree;
struct nod {
	int id, s;
}p[maxn];
int f[55][maxn], save[maxn];
int N, K, M;

bool cmpS(nod A, nod B)
{
	return A.s < B.s;
}

bool cmpID(nod A, nod B)
{
	return A.id < B.id;
}

int main()
{
	freopen("in", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> p[i].s;
		p[i].id = i;
	}
	sort(p + 1, p + N + 1, cmpS);
	M = 1;
	int now = p[1].s;
	p[1].s = M;
	for (int i = 2; i <= N; i++) {
		if (p[i].s != now) {
			M++;
			now = p[i].s;
			p[i].s = M;
		} else p[i].s = M;
	}
	sort(p + 1, p + N + 1, cmpID);
	memset(save, 0, sizeof(save));
	for (int i = 1; i <= N; i++) {
		f[1][i] = 1 - save[p[i].s];
		save[p[i].s] = 1;
	}
	for (int i = 2; i <= K; i++) {
		tree.init(M);
		memset(save, 0, sizeof(save));
		for (int j = 1; j <= N; j++) {
			int tmp = save[p[j].s];
			save[p[j].s] = tree.sum(p[j].s - 1);
			f[i][j] = (save[p[j].s] - tmp + mod) % mod;
			tree.add(p[j].s, f[i - 1][j]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; i++)
		ret = (ret + f[K][i]) % mod;
	cout << ret << endl;
	return 0;
}
